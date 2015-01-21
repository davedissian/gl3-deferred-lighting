/*
 * GL Framework
 * Copyright (c) David Avedissian 2014-2015
 */
#ifndef MAIN_H
#define MAIN_H

class DeferredShading : public Framework
{
public:
    virtual void setup();
    virtual void render();
    virtual void cleanup();

private:
    GLuint mVAO;
    GLuint mVBO;
    shared_ptr<Shader> mShader;
};

#endif /* MAIN_H */
