#pragma once

#include <gfx/application.h>

class FluidSimulation : public core::Application {
public:
  FluidSimulation();

  void Initialize() override;
  void Update(float delta_time) override;
  void Render(float aspect_ratio) override;
  void Shutdown() override;

private:
};