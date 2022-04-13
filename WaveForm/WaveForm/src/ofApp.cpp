#include "ofApp.h"
#include <sys/stat.h>
#include <string>
#include <fstream>

#include "boost/filesystem.hpp"
#include "ext/DrawType.h"




 bool IsValidFile(const std::string& name) {

	return  boost::filesystem::exists(name);
}

 void PrintOut()
 {

	std::cout << "time" << std::endl;
 }

//--------------------------------------------------------------

void ofApp::setup()
{

	GUI.setup();
	GUI.add(VOL.set("volume", .5, .0, 1.));
	GUI.add(DECAY.set("Decay", .5, .0, 1.0));
	GUI.add(FilePath.set("C:/dev/MusicVisualiser/WaveForm/WaveForm/bin/data/partytime_04.wav"));
	f = FilePath;
	shader.load("shader");


	fft = new float[128];
	for (int i = 0; i < 128; i++) {
		fft[i] = 0;
	}

	bands = 64;

}

//--------------------------------------------------------------

void ofApp::update() {

	

	if (f.compare(FilePath))
	{
		f = FilePath;
		HasSet = false;
	}

	if (!HasSet) {


		std::string name = "search";
		std::string folder = "C:/dev/MusicVisualiser/WaveForm/WaveForm/bin/data/";
		ofFileDialogResult MainFile = ofSystemLoadDialog(name, false, folder);

		if (MainFile.bSuccess)
		{
			string path = MainFile.getPath();
		
			f = path;
			sound.load(f);
			sound.play();
			sound.setLoop(true);
			FilePath = path;
			
			//not sure if this is needed anymore tested on linux and it was ok :3
			if (!IsValidFile(f))
			{
				std::cout << "warning boost is saying this is an invalid file" << std::endl;
			}
		}
		
		HasSet = true;

	}




	if (!HasSetTime) {

		//auto s = PrintOut;
		TIMEBASE = new TimeBase();

		HasSetTime = true;

	}


	//std::cout << TIMEBASE->GetTime() << std::endl;

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


	Element * A;
	if (!&A) {
		A = new Element();
	}


   DrawElementCommand(
	A->SetUpElement(shader,"u_Time", red, 0.0); 
	A->SetUpElement(shader, "u_ATime", TIMEBASE->GetTime(), 0.0);
	A->SetUpElement(shader, "u_resolution", ofGetWidth()*1.0f, ofGetHeight()*1.0f);
	)
		
}


void ofApp::draw(){
	DrawElementCommand(ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());)
	GUI.draw();
	
}



