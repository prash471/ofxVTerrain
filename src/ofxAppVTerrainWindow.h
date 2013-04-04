//
//  ofAppOsgWindow.h
//  emptyExample
//
//  Created by Stephan Huber on 26.03.11.
//  Copyright 2011 Digital Mind. All rights reserved.
//

#ifndef OF_APP_OSG_WINDOW_HEADER
#define OF_APP_OSG_WINDOW_HEADER

#include "ofAppBaseWindow.h"
#include <osgViewer/View>

#include "vtlib/vtlib.h"
#include "vtlib/core/Terrain.h"
#include "vtlib/core/TerrainScene.h"
#include "vtlib/core/NavEngines.h"
#include "vtlib/vtosg/OSGEventHandler.h"
#include "vtdata/DataPath.h"
#include "vtdata/vtLog.h"

namespace osgViewer {
    class CompositeViewer;
    class GraphicsWindow;
}

class ofxAppVTerrainWindow : public ofAppBaseWindow {
public:
    ofxAppVTerrainWindow();
    
    virtual void setupOpenGL(int w, int h, int screenMode);
	virtual void initializeWindow();
	virtual void runAppViaInfiniteLoop(ofBaseApp * appPtr);
    
	virtual void hideCursor();
	virtual void showCursor();
    
	virtual void	setWindowPosition(int x, int y);
	virtual void	setWindowShape(int w, int h);
    
	virtual int		getFrameNum() { return _frameNumber; }
	virtual	float	getFrameRate() {return _frameRate; }
	virtual double  getLastFrameTime(){ return _lastFrameTime; }
    
	virtual ofPoint	getWindowPosition();
	virtual ofPoint	getWindowSize();
	virtual ofPoint	getScreenSize();
    
	virtual void	setFrameRate(float targetRate){}
	virtual void	setWindowTitle(string title);
    
	virtual int		getWindowMode() {return 0;}
    
	virtual void	setFullscreen(bool fullscreen);
	virtual void	toggleFullscreen();
    
	virtual void	enableSetupScreen(){ _setupScreen = true; }
	virtual void	disableSetupScreen(){ _setupScreen = false; }
    
    inline bool setupScreenEnabled() const { return _setupScreen; }
    
protected:
    
    void setView(osgViewer::View* view) { _view = view; }
    osgViewer::View* getView() { return _view; }
    ofBaseApp* getApp() { return _app; }
    osgViewer::GraphicsWindow* getGraphicsWindow();
    
    osg::ref_ptr<osgViewer::View> _view;
    ofBaseApp*                     _app;
    unsigned int _w, _h;
    bool    _setupScreen;
    
    int _frameNumber;
    float _frameRate;
    double _lastFrameTime;
    
    friend class ofCameraPreDrawCallback;
    int _screenMode;
    
    osg::ref_ptr<osg::GraphicsContext::Traits> _savedTraits;

	vtTerrainScene *g_terrscene;
	// Get a handle to the vtScene - one is already created for you
	vtScene *_pScene;

};


#endif