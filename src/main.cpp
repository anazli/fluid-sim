#include "fluid_simulation.h"

#include <gfx/window.h>

int main() {
  core::AppWindow window(800, 600, "Fluid Simulation");

  auto fluid_simulation = std::make_unique<FluidSimulation>();
  fluid_simulation->Initialize();

  window.Render(fluid_simulation.get());

  fluid_simulation->Shutdown();

  return 0;
}