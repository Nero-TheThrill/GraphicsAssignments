#include "camera.hpp"

int main(int argc, char** argv)
{
    try
    {
        App app(argc, argv, "A3 - World and camera");

        Program program(
            std::string(SHADER_DIR) + "/scene.vert",
            std::string(SHADER_DIR) + "/scene.frag"
        );

        Mesh house;
        createMesh(house, houseVertices(), houseIndices());

        auto world = makeWorld(house);
        Camera camera;

        while (app.begin())
        {
            // TODO A3.7: update viewport with framebuffer dimensions and update camera state.
            // Hint: Call glViewport(x, y, width, height) and updateCamera(camera, app).
            // app.width / app.height are refreshed every frame, including after resize.

            glUseProgram(program.id);
            uploadCamera(program.id, camera, app.width, app.height);

            for (const auto& o : world)
                drawObject(o, program.id);

            app.end();
        }

        return 0;
    }
    catch (const std::exception& e)
    {
        std::fprintf(stderr, "%s\n", e.what());
        return 1;
    }
}
