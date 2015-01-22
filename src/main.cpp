/*
 * GL Framework
 * Copyright (c) David Avedissian 2014-2015
 */
#include "common.h"
#include "framework.h"
#include "shader.h"
#include "texture.h"
#include "main.h"

int main()
{
    return DeferredShading().run(1024, 768);
}

void DeferredShading::setup()
{
    mShader = Shader::Builder().vs("media/sample.vs").fs("media/sample.fs").link();
    mTexture = make_shared<Texture>("media/sample.png");

    // Create a vertex array object to store vertex buffer and layout
    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);

    // Vertices
    static const float vertices[] = {
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f,
        0.5f, -0.5f, 0.0f, 1.0f, 1.0f,
        0.0f, 0.5f, 0.0f, 0.5f, 0.0f
    };

    // Generate vertex buffer
    glGenBuffers(1, &mVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Set up vertex layout
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), NULL);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
}

void DeferredShading::render()
{
    mShader->bind();
    glBindVertexArray(mVAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void DeferredShading::cleanup()
{
    mShader.reset();
}
