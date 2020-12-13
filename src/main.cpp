#include <stdio.h>
#include "terrabyte.h"

pkr::TERRABYTE_ENGINE* engine;

void Update(double dt)
{

}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1,1,1,1);
}

int main()
{
    engine = pkr::CreateEngine(800, 600, "Title");
    pkr::StartEngine(*engine, &Update, &Draw);
    return 0;
}