#pragma once
#include "../ofApp.h"
#include <iostream>


#define DrawElementCommand(x)shader.begin(); x shader.end();

	class Element : public ofBaseApp {

	public:

		template<typename T>
		bool CheckData(T A);
		void SetUpElement(ofShader &ShaderInst, std::string ParamName, float float1, float float2);
		
		//~Element();

	};

	

