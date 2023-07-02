#include "raisim/World.hpp"
#include "raisim/RaisimServer.hpp"

int main(int argc, char* argv[]) {
  auto binaryPath = raisim::Path::setFromArgv(argv[0]);

  raisim::World world;
  auto laikago = world.addArticulatedSystem(binaryPath.getDirectory() + "\\rsc\\laikago\\laikago.urdf");
  auto ball = world.addSphere(0.1, 1);
  auto ground = world.addGround(-2);
  world.setTimeStep(0.002);

  /// launch raisim server for visualization. Can be visualized using raisimUnity
  raisim::RaisimServer server(&world);
  server.launchServer();

  for (int i=0; i<10000; i++) {
    RS_TIMED_LOOP(world.getTimeStep()*1e6);
    server.integrateWorldThreadSafe();
  }

  server.killServer();
}
