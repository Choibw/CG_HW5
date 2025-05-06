#include "SceneGenerator.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

std::vector<glm::vec3> gVertexBuffer;
std::vector<glm::uvec3> gIndexBuffer;

void create_scene()
{
    int width = 32;
    int height = 16;
    float theta, phi;

    gVertexBuffer.clear();
    gIndexBuffer.clear();

    // 본체 정점
    for (int j = 1; j < height - 1; ++j)
    {
        for (int i = 0; i < width; ++i)
        {
            theta = (float)j / (height - 1) * M_PI;
            phi = (float)i / (width - 1) * M_PI * 2;

            float x = sinf(theta) * cosf(phi);
            float y = cosf(theta);
            float z = -sinf(theta) * sinf(phi);

            gVertexBuffer.push_back(glm::vec3(x, y, z));
        }
    }

    // 북극/남극
    gVertexBuffer.push_back(glm::vec3(0, 1, 0));   // 북극
    gVertexBuffer.push_back(glm::vec3(0, -1, 0));  // 남극

    int last = gVertexBuffer.size();
    int northPoleIdx = last - 2;
    int southPoleIdx = last - 1;

    // 본체 삼각형
    for (int j = 0; j < height - 3; ++j)
    {
        for (int i = 0; i < width - 1; ++i)
        {
            int a = j * width + i;
            int b = (j + 1) * width + (i + 1);
            int c = j * width + (i + 1);
            int d = (j + 1) * width + i;

            gIndexBuffer.push_back(glm::uvec3(a, b, c));
            gIndexBuffer.push_back(glm::uvec3(a, d, b));
        }
    }

    // 북극 삼각형
    for (int i = 0; i < width - 1; ++i)
    {
        gIndexBuffer.push_back(glm::uvec3(northPoleIdx, i, i + 1));
    }

    // 남극 삼각형
    int base = (height - 3) * width;
    for (int i = 0; i < width - 1; ++i)
    {
        gIndexBuffer.push_back(glm::uvec3(southPoleIdx, base + (i + 1), base + i));
    }
}
