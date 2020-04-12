#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/CinderImGui.h"

using namespace ci;
using namespace ci::app;

class RobotSimulation : public App {
  public:
	void setup() override;
	void draw() override;
	
	CameraPersp		mCam;
	gl::BatchRef	mBox;
};

void RobotSimulation::setup()
{
	mCam.lookAt( vec3( 0, 4.5, 0 ), vec3( 0, 0, 0 ) );

	ImGui::Initialize();
}

void RobotSimulation::draw()
{
	gl::clear();
	gl::enableDepthRead();
	gl::enableDepthWrite();

	gl::setMatrices( mCam );

	static float rotationX = 0;
	static float rotationY = 0;
	static float rotationZ = 0;

	ImGui::Begin("Control");
	ImGui::SliderFloat("rotation X", &rotationX, -3.14, 3.14);
	ImGui::SliderFloat("rotation Y", &rotationY, -3.14, 3.14);
	ImGui::SliderFloat("rotation Z", &rotationZ, -3.14, 3.14);

	ImGui::End();

	auto lambert = gl::ShaderDef().lambert().color();
	auto shader = gl::getStockShader( lambert );
	shader->bind();

	gl::rotate( vec3( rotationX, rotationY, rotationZ ) );
	gl::color( Color( 1, 0, 0 ) );
	gl::drawCube( vec3(), vec3( 1 ) );
}

CINDER_APP( RobotSimulation, RendererGl )