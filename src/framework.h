/*
 * GL Framework
 * Copyright (c) David Avedissian 2014-2015
 */
#ifndef FRAMEWORK_H
#define FRAMEWORK_H

class Framework
{
public:
    Framework();
    ~Framework();

    void printSDLError();
    int createWindow(unsigned int width, unsigned int height);
    void destroyWindow();

    int run(unsigned int width, unsigned int height);

    virtual void setup() = 0;
    virtual void render() = 0;
    virtual void cleanup() = 0;

private:
    SDL_Window* mWindow;
    SDL_GLContext mContext;
};

#endif /* FRAMEWORK_H */
