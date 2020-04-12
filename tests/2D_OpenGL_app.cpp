#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;

class BasicApp : public App {
  public:
	void draw() override;
};

void BasicApp::draw()
{
	gl::clear();

	// preserve the default Model matrix
	gl::pushModelMatrix();
	// move to the window center
	gl::translate( getWindowCenter() );

	int numCircles = 16;
	float radius = getWindowHeight() / 2 - 30;
	
	for( int c = 0; c < numCircles; ++c ) {
		float rel = c / (float)numCircles;
		float angle = rel * M_PI * 2;
		vec2 offset( cos( angle ), sin( angle ) ); 
		
		// preserve the Model matrix
		gl::pushModelMatrix();
		// move to the correct position
		gl::translate( offset * radius );
		// set the color using HSV color
		gl::color( Color( CM_HSV, rel, 1, 1 ) );
		// draw a circle relative to Model matrix
		gl::drawStrokedCircle( vec2(), 30 );
		// restore the Model matrix
		gl::popModelMatrix();
	}

	// draw a white circle at window center
	gl::color( Color( 1, 1, 1 ) );
	gl::drawSolidCircle( vec2(), 15 );

	// restore the default Model matrix
	gl::popModelMatrix();
}

CINDER_APP( BasicApp, RendererGl )