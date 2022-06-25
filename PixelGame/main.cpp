#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
class DemoGame :public olc::PixelGameEngine{
public:
    DemoGame()
    {
        sAppName = "Example";
    }

public:
    bool OnUserCreate() override
    {
        // Called once at the start, so create things here

        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override
    {
        // called once per frame
//        for (int x = 0; x < ScreenWidth(); x++)
//            for (int y = 0; y < ScreenHeight(); y++)
//                Draw(x, y, olc::Pixel(rand() % 255, rand() % 255, rand()% 255));
        DrawLine(olc::vi2d(0,100),olc::vi2d(100,100));
        return true;
    }

};

int main(){

    DemoGame demo;
    if (demo.Construct(256, 240, 2, 2))
        demo.Start();

    return 0;
}