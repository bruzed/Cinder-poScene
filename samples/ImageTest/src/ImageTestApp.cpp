#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

#include "poScene.h"
#include "poImageTestApp.h"

class ImageTestApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    po::SceneRef scene;
};

void ImageTestApp::setup()
{
    ci::gl::enableAlphaBlending();
    
    poImageTestAppRef app = poImageTestApp::create();
    scene = po::Scene::create(app);
}

void ImageTestApp::mouseDown( MouseEvent event )
{
}

void ImageTestApp::update()
{
    scene->update();
}

void ImageTestApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    scene->draw();
}

CINDER_APP_NATIVE( ImageTestApp, RendererGl )