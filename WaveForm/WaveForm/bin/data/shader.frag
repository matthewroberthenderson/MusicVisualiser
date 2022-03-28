#version 150

out vec4 outputColor;
uniform float u_Time;
uniform vec2 u_resolution;
uniform float u_ATime;

float SQUARES_TO_TRIANGLES = (3.0 - sqrt(3.0)) / 6.0;
float TRIANGLES_TO_SQUARES = (sqrt(3.0) - 1.0) / 2.0;

float random (vec2 uv) {
    return fract(sin(dot(uv, vec2(12.9898,78.233))) * 43758.5453123);
}

float simplexValue2DPart(vec2 uv, vec2 iuv) {
    float unskew = (iuv.x + iuv.y) * SQUARES_TO_TRIANGLES;
    float x = uv.x - iuv.x + unskew;
    float y = uv.y - iuv.y + unskew;
    float f = 0.5 - x * x - y * y;
    return f * f * f * random(iuv);
}

float simplexValue2D(in vec2 uv) {
    float skew = (uv.x + uv.y) * TRIANGLES_TO_SQUARES;
    vec2 skewUV = uv + skew;
    vec2 iuv = floor(skewUV);
    
    // Get bottom left corner
    float n = simplexValue2DPart(uv, iuv);
    
    // Get top right corner
    n += simplexValue2DPart(uv, iuv + 1.0);
    
    if (skewUV.x - iuv.x >= skewUV.y - iuv.y) {
    	// Get bottom right corner
        n += simplexValue2DPart(uv, iuv + vec2(1.0, 0.0));
    } else {
        // Get top left corner
        n += simplexValue2DPart(uv, iuv + vec2(0.0, 1.0));
    }
    
    return n * (8.0 * 2.0) - 1.0;
}




vec3 Chromatic_04()
{

 vec3 c;
	float l,z=u_Time;

	for(int i=0;i<3;i++) {
		vec2 u2v,p=gl_FragCoord.xy/u_resolution;
		u2v=p + u_Time;
		p-=.5;
		p.x*=u_resolution.x/u_resolution.y;
		z+=.07;
		l=length(simplexValue2D((gl_FragCoord.xy/u_resolution) + vec2(u_Time,0.0)));
		u2v+=p/l*(sin(u_Time)+1.)*abs(sin(l*9.-z-z));
		c[i]=.01/length(mod(u2v,1.)-.5);
	}

	return vec3(((c * (simplexValue2D(gl_FragCoord.xy/u_resolution * 12.0f))*12.0f)/l));
}





vec3 Chromatic_03()
{

  vec3 c;
	float l,z=u_Time;

	for(int i=0;i<3;i++) {
		vec2 u2v,p=gl_FragCoord.xy/u_resolution;
		u2v=p + u_Time;
		p-=.5;
		p.x*=u_resolution.x/u_resolution.y;
		z+=.07;
		l=length(simplexValue2D((gl_FragCoord.xy/u_resolution) + vec2(u_Time,0.0)));
		u2v+=p/l*(sin(u_Time)+1.)*abs(sin(l*9.-z-z));
		c[i]=.01/length(mod(u2v,1.)-.5);
	}
		
	return vec3((c/l));
}





vec3 Chromatic_02()
{

    vec3 c;
	float l,z=u_Time;
	//simplexValue2D(gl_FragCoord.xy/u_resolution)
	for(int i=0;i<3;i++) {
		vec2 u2v,p=gl_FragCoord.xy/u_resolution;
		u2v=p + u_Time + (simplexValue2D(gl_FragCoord.xy/u_resolution) * 12.1f);
		p-=.5;
		p.x*=u_resolution.x/u_resolution.y;
		z+=.07;
		l=step(length(p),0.5);
		u2v+=p/l*(sin(u_Time)+1.)*abs(sin(l*9.-z-z));
		c[i]=.01/length(mod(u2v,1.)-.5);
	}
		
	return vec3((c/l));
}




vec3 Chromatic_01()
{

    vec3 c;
	float l,z=u_Time;

	for(int i=0;i<3;i++) {
		vec2 u2v,p=gl_FragCoord.xy/u_resolution;
		u2v=p + u_Time;
		p-=.5;
		p.x*=u_resolution.x/u_resolution.y;
		z+=.07;
		l=length(p);
		u2v+=p/l*(sin(u_Time)+1.)*abs(sin(l*9.-z-z));
		c[i]=.01/length(mod(u2v,1.)-.5);
	}
		
	return vec3((c/l));
}



void main()
{

vec2 coord = gl_FragCoord.xy;
vec2 screen = (coord / u_resolution);
vec3 Color;
float T =  mod(u_ATime,300.0);


   if((T) < 100.0)
   {
        Color = Chromatic_04();
   }

   else if (T > 100.0 && T < 200.0 )
   {
        Color = Chromatic_02();
   }

   else if(T > 200.0) 
   {
        Color = Chromatic_03();
   }


	float green = 0.5;
	float blue = 0.3;
	float alpha = 1.0;
	outputColor = vec4(Color,1.0);


}