#version 330
#include "../lib/fragDeferredWrite.glsl"

// In put
in struct
{
	vec3 WorldSpacePos;
	vec3 Normal;
	vec4 VertexColorMCCV;
	vec2 TexCoordDetail;
	vec2 TexCoordAlpha;
} VSInput;

// Diffuses
uniform sampler2D gColorMap[4];

// Speculars textures
uniform sampler2D gSpecularMap[4];

// Alpha Textures + Shadow Texture
uniform sampler2D gBlend;

// Shadow Params
uniform bool gShadowMapExists;
uniform vec3 gShadowColor;

void main()
{
	vec3 resultColor = vec3(0.0f);
	vec4 resultSpecular = vec4(0.0f);
	float alphaSumma = 0.0f;

	// Layer 1
	float alpha0 = texture(gBlend, VSInput.TexCoordAlpha)[0];
	resultColor = mix(resultColor, texture(gColorMap[1], VSInput.TexCoordDetail).rgb, alpha0);
	resultSpecular = mix(resultSpecular, texture(gSpecularMap[1], VSInput.TexCoordDetail), alpha0);
	alphaSumma += alpha0;

	// Layer 2
	float alpha1 = texture(gBlend, VSInput.TexCoordAlpha)[1];
	resultColor = mix(resultColor, texture(gColorMap[2], VSInput.TexCoordDetail).rgb, alpha1);
	resultSpecular = mix(resultSpecular, texture(gSpecularMap[2], VSInput.TexCoordDetail), alpha1);
	alphaSumma += alpha1;

	// Layer 3
	float alpha2 = texture(gBlend, VSInput.TexCoordAlpha)[2];
	resultColor = mix(resultColor, texture(gColorMap[3], VSInput.TexCoordDetail).rgb, alpha2);
	resultSpecular = mix(resultSpecular, texture(gSpecularMap[3], VSInput.TexCoordDetail), alpha2);
	alphaSumma += alpha2;

	// General
	resultColor = texture(gColorMap[0], VSInput.TexCoordDetail).rgb * (1.0f - alphaSumma) + resultColor;
	resultSpecular = texture(gSpecularMap[0], VSInput.TexCoordDetail) * (1.0f - alphaSumma) + resultSpecular;

	if (gShadowMapExists)
	{
		float alphaShadow = texture(gBlend, VSInput.TexCoordAlpha)[3];
		resultColor = mix(resultColor, gShadowColor, alphaShadow);
	}

	setMatID(1.0);
	setPos(VSInput.WorldSpacePos);
	setNormal(VSInput.Normal);
	setAlbedo(resultColor.rgb);
	setSpecParams(resultSpecular.rgb, 1.0);
};
