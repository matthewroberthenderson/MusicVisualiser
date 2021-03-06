#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ext/DrawType.h"
#include "../src/Helpers/Helpers.h"
#include "ofShader.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void exit();

		std::string  f;
		std::string  G;

		

		//timer 
		TimeBase *  TIMEBASE;
		bool HasSetTime = false;


		//GUI
		bool HasSet = false;
		ofxPanel GUI;
		ofParameter<float> VOL;
		ofParameter<float> DECAY;
		ofParameter<string> FilePath;
		
		ofSoundPlayer sound;

		float *fft;
		float *soundSpectrum;
		int bands;

		void Vis_SphereLidar();	
		ofTrueTypeFont font;
		int font_size;

		vector<glm::vec3> location_list;
		vector<int> life_list;
		vector<float> noise_param_list;
		vector<glm::vec3> noise_location_list;

		ofEasyCam cam;
		ofMesh face, frame;

		ofShader shader;
};
