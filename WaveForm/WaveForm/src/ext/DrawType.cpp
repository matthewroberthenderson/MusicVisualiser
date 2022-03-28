#include "DrawType.h"


	template<typename T>
	bool Element::CheckData(T A)
	{
		if (A > 0.0) {
			return true;

		}
		else {
			return false;
		}
	}

	void Element::SetUpElement(ofShader &ShaderInst, std::string ParamName, float float1, float float2)
	{

		if ((float1 * float2) > 0.0)
		{
			ShaderInst.setUniform2f
			(
				ParamName,
				float1,
				float2
			);
		}

		else
		{
			ShaderInst.setUniform1f
			(
				ParamName,
				float1
			);

		}


	}