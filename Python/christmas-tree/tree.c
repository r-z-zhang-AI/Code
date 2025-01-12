#include <SDL2/SDL.h>
#include <stdlib.h>
#include <time.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define WIDTH 800
#define HEIGHT 600

void draw_triangle(SDL_Renderer* renderer, int x0, int y0, int x1, int y1, int x2, int y2) {
    SDL_RenderDrawLine(renderer, x0, y0, x1, y1);
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    SDL_RenderDrawLine(renderer, x2, y2, x0, y0);
}

void draw_tree(SDL_Renderer* renderer, int height) {
    int tree_width = WIDTH / 2;
    int tree_height = HEIGHT - 150;  // Reserve space for trunk and decorations
    int level_height = tree_height / height;
    int x0, x1, y0, y1;

    // Draw tree body (multiple triangles)
    for (int i = 0; i < height; i++) {
        x0 = WIDTH / 2 - (i + 1) * tree_width / (2 * height);
        x1 = WIDTH / 2 + (i + 1) * tree_width / (2 * height);
        y0 = 50 + i * level_height - (i * 5);
        y1 = 50 + (i + 1) * level_height - (i * 5);

        // Draw triangle for the tree level
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Green color
        draw_triangle(renderer, x0, y1, x1, y1, WIDTH / 2, y0);

        // Draw decorations
        int num_decorations = (i < height - 1) ? rand() % 5 + 3 : rand() % 6 + 25;
        for (int j = 0; j < num_decorations; j++) {
            int decoration_x = rand() % (x1 - x0 + 1) + x0;
            int decoration_y = rand() % (y1 - y0 + 1) + y0;

            // Randomly choose a decoration shape (simplified to circles here)
            SDL_SetRenderDrawColor(renderer, rand() % 256, rand() % 256, rand() % 256, 255);
            SDL_RenderDrawPoint(renderer, decoration_x, decoration_y);
        }
    }

    // Draw trunk
    int trunk_width = tree_width / 7;
    int trunk_height = 70;
    x0 = WIDTH / 2 - trunk_width / 2;
    x1 = WIDTH / 2 + trunk_width / 2;
    y0 = 50 + height * level_height - (height - 1) * 5;
    y1 = y0 + trunk_height;
    SDL_SetRenderDrawColor(renderer, 139, 69, 19, 255); // Brown color
    SDL_RenderFillRect(renderer, &(SDL_Rect){x0, y0, trunk_width, trunk_height});
}

void draw_star(SDL_Renderer* renderer) {
    int star_size = 50;
    int star_x = WIDTH / 2;
    int star_y = 50;

    // Draw a simple star (represented by a 5-pointed shape)
    SDL_SetRenderDrawColor(renderer, 255, 223, 0, 255); // Gold color
    SDL_RenderDrawLine(renderer, star_x, star_y - star_size,
                              star_x + star_size / 2, star_y + star_size / 3);
    SDL_RenderDrawLine(renderer, star_x + star_size / 2, star_y + star_size / 3,
                              star_x - star_size / 2, star_y + star_size / 3);
    SDL_RenderDrawLine(renderer, star_x - star_size / 2, star_y + star_size / 3,
                              star_x, star_y - star_size);
}

void draw_spiral_ribbon(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 215, 0, 255); // Gold color for ribbon
    int spiral_angle = 0;
    int radius = 120;

    for (int i = 0; i < 40; i++) {
        spiral_angle += 5;
        radius += 2;
        int x = WIDTH / 2 + radius * cos(spiral_angle * M_PI / 180);
        int y = 50 + i * 2 + radius * sin(spiral_angle * M_PI / 180);
        SDL_RenderDrawPoint(renderer, x, y);
    }
}

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("Christmas Tree", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    srand(time(NULL));

    // Main render loop
    int height = 10;
    int running = 1;
    while (running) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = 0;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Set background to white
        SDL_RenderClear(renderer);

        draw_tree(renderer, height);
        draw_star(renderer);
        draw_spiral_ribbon(renderer);

        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
