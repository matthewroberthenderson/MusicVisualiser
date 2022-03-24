#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup()
{


	sound.load("party time_04.wav");
	sound.play();
	sound.setLoop(true);

	shader.load("shader");
	
	GUI.setup();
	GUI.add(VOL.set("volume", .5, .0, 1.));
	GUI.add(DECAY.set("Decay", .5, .0, 1.0));
	GUI.add(MESSAGE.set("Welcome"));

	fft = new float[128];
	for (int i = 0; i < 128; i++) {
		fft[i] = 0;
	}

	bands = 64;

}

//--------------------------------------------------------------
void ofApp::update(){

	timer += 0.1;
	ofSoundUpdate();

	sound.setVolume(VOL);
	soundSpectrum = ofSoundGetSpectrum(bands);

	for (int i = 0; i < bands; i++)
	{
		fft[i] *= DECAY;
		if (fft[i] < soundSpectrum[i])
		{
			fft[i] = soundSpectrum[i];
		}
	}


	float red;

	if (&fft[0] != nullptr) {
		red = (fft[0] * 1.0f);
	}

	red = (fft[0] * 10.0f);

    
	shader.begin();
	shader.setUniform1f
	(
		"u_Time", 
		red
	);

	shader.setUniform1f
	(
		"u_ATime",
		timer
	);

	shader.setUniform2f
	(
		"u_resolution", 
		ofGetWidth()*1.0f, 
		ofGetHeight()*1.0f
	);
	shader.end();



}

//--------------------------------------------------------------
void ofApp::draw(){

	shader.begin();
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	shader.end();

	GUI.draw();
	
}



