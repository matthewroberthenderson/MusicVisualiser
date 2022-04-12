#pragma once
#include "../ofApp.h"
#include <iostream>
#include <vector>


#define DrawElementCommand(x)shader.begin(); x shader.end();

	class Element : public ofBaseApp {

	public:

		template<typename T>
		bool CheckData(T A);
		void SetUpElement(ofShader &ShaderInst, std::string ParamName, float float1, float float2);
		

		// -- template -- 

		std::vector<float>ParamArray;

		std::tuple<float> * Param  = new std::tuple<float>;
		
		
		template<typename T>
		void AddData(ofShader &ShaderInst, std::string ParamName, T data) {}
		
		template<>
		void AddData<int>(ofShader &ShaderInst, std::string ParamName,int data) {}

		template<>
		void AddData<float>(ofShader &ShaderInst, std::string ParamName, float data) {}

		template<>
		void AddData<char>(ofShader &ShaderInst, std::string ParamName, char data) {}

	};

	

