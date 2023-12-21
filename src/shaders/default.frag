#version 330 core

in vec3 color;
in vec2 tex;
in vec3 normal;
in vec3 modelPos;

uniform sampler2D tex0;
uniform vec4 lightColor;
uniform vec3 lightPos;
uniform vec3 camPos;

out vec4 FragColor;

vec4 getColor()
{
	if (color.x > 0 || color.y > 0 || color.z > 0) {
		return vec4(color, 1.0f);
	} else {
		return texture(tex0, tex);
	}
}

void main()
{
	// ambient lighting
	float ambient = 0.20f;

	// diffuse lighting
	vec3 norm = normalize(normal);
	vec3 lightDirection = normalize(lightPos - modelPos);
	float diffuse = max(dot(norm, lightDirection), 0.0f);

	// specular lighting
	float specularLight = 0.50f;
	vec3 viewDirection = normalize(camPos - modelPos);
	vec3 reflectionDirection = reflect(-lightDirection, norm);
	float specAmount = pow(max(dot(viewDirection, reflectionDirection), 0.0f), 16);
	float specular = specAmount * specularLight;

	FragColor = getColor() * lightColor * (diffuse + ambient + specular);
}