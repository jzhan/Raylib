// g++ main.cpp -o main -L"C:\Users\jzhan\Desktop\Raylib\lib" -lraylib -lopengl32 -lgdi32 -lwinmm

#include <raylib.h>

class Creature {
public:
    Texture2D texture;
    Rectangle frame;
};

Rectangle MEGAMAN_WALKING_FRAME[16] = {
    {8, 256, 40, 45}, 
    {MEGAMAN_WALKING_FRAME[0].x + MEGAMAN_WALKING_FRAME[0].width, 256, 40, 45},
    {MEGAMAN_WALKING_FRAME[1].x + MEGAMAN_WALKING_FRAME[1].width, 256, 40, 45},
    {MEGAMAN_WALKING_FRAME[2].x + MEGAMAN_WALKING_FRAME[2].width, 256, 44, 45},
    {MEGAMAN_WALKING_FRAME[3].x + MEGAMAN_WALKING_FRAME[3].width, 256, 48, 45},
    {MEGAMAN_WALKING_FRAME[4].x + MEGAMAN_WALKING_FRAME[4].width, 256, 50, 45},
    {MEGAMAN_WALKING_FRAME[5].x + MEGAMAN_WALKING_FRAME[5].width, 256, 38, 45},
    {MEGAMAN_WALKING_FRAME[6].x + MEGAMAN_WALKING_FRAME[6].width + 2, 256, 32, 45},
    {MEGAMAN_WALKING_FRAME[7].x + MEGAMAN_WALKING_FRAME[7].width + 4, 254, 26, 45},
    {MEGAMAN_WALKING_FRAME[8].x + MEGAMAN_WALKING_FRAME[8].width, 254, 38, 45},
    {MEGAMAN_WALKING_FRAME[9].x + MEGAMAN_WALKING_FRAME[9].width, 256, 42, 45},
    {MEGAMAN_WALKING_FRAME[10].x + MEGAMAN_WALKING_FRAME[10].width, 256, 52, 45},
    {MEGAMAN_WALKING_FRAME[11].x + MEGAMAN_WALKING_FRAME[11].width, 256, 58, 45},
    {MEGAMAN_WALKING_FRAME[12].x + MEGAMAN_WALKING_FRAME[12].width, 256, 44, 45},
    {MEGAMAN_WALKING_FRAME[13].x + MEGAMAN_WALKING_FRAME[13].width, 256, 44, 45},
    {MEGAMAN_WALKING_FRAME[14].x + MEGAMAN_WALKING_FRAME[14].width, 254, 40, 45}
};

int main() {
    const int screen_width = 800;
    const int screen_height = 560;

    InitWindow(screen_width, screen_height, "Farm");

    Creature hero;

    hero.texture = LoadTexture("megaman_x.png");
    hero.frame = MEGAMAN_WALKING_FRAME[0];

    Camera2D camera = {0};
    camera.offset = {screen_width / 2, screen_height / 2};
    camera.rotation = 0;
    camera.target = {screen_width / 2, screen_height / 2};
    camera.zoom = 5;

    SetTargetFPS(10);

    int i = 1;

    while(!WindowShouldClose()) {
        if(IsKeyPressed(KEY_ESCAPE)) 
            return 0;
        
        hero.frame = MEGAMAN_WALKING_FRAME[i];
        i = (i + 1) % 15 + 1;

        camera.zoom += GetMouseWheelMove() * 0.05f;

        BeginDrawing();

        ClearBackground(BLACK);

        BeginMode2D(camera);

        DrawTextureRec(hero.texture, hero.frame, 
            {screen_width / 2, screen_height / 2}, WHITE);

        EndMode2D();
        EndDrawing();
    }
}
