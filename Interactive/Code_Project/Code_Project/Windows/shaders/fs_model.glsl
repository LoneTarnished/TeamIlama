#version 410 core

out vec4 FragColor;

in VS_OUT
{
    vec3 vertex;
    vec3 normals;
    vec2 tc;
} fs_in;

uniform sampler2D tex;
uniform mat4 model_matrix;
uniform vec3 lightPos1;
uniform vec3 viewPos;
uniform vec3 lightColor1;
uniform bool blinn;

uniform vec3 spotLightColor1;
uniform vec3 spotLightColor2;
uniform vec3 spotLightColor3;

uniform vec3 spotLightDirection1;
uniform vec3 spotLightDirection2;
uniform vec3 spotLightDirection3;

uniform float cutoffAngle;

uniform vec3 spotLightPosition;

uniform float kc;
uniform float kl;
uniform float kq;

uniform bool enableSpotLight1;
uniform bool enableSpotLight2;
uniform bool enableSpotLight3;

vec3 computeSpotLight(vec3 lightDirection, vec3 spotLightDirection, vec3 spotLightColor)
{
	float theta = dot(lightDirection, normalize(-spotLightDirection));

	vec3 diffuseLightColor = vec3(0.0, 0.0, 0.0);

	if(theta > cutoffAngle) 
	{       
		// do lighting calculations
		float diffuse = clamp(dot(fs_in.normals, lightDirection), 0.0, 1.0);

		diffuseLightColor = spotLightColor * diffuse;
	}

	return diffuseLightColor;
}

void main(void){
    vec3 color = texture(tex, fs_in.tc).rgb;

    if (color.r < 0.001)
    {
      color = vec3(1.0);
    }

    // ambient
    vec3 ambient = 0.3 * color;

    // diffuse
    vec3 lightDir = normalize(lightPos1 - fs_in.vertex);
    vec3 normal = normalize(fs_in.normals);
    float diff = max(dot(lightDir, normal), 0.0);
    vec3 diffuse = diff * color;

    vec3 lightDir2 = vec3(1.0, 1.0, 1.0);
    float diff2 = max(dot(lightDir2, normal), 0.0);
    vec3 diffuse2 = diff2 * color * lightColor1;

    // specular
    vec3 viewDir = normalize(viewPos - fs_in.vertex);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = 0.0;

    if(blinn)
    {
        vec3 halfwayDir = normalize(lightDir + viewDir);
        spec = pow(max(dot(normal, halfwayDir), 0.0), 32.0);
    }
    else
    {
        vec3 reflectDir = reflect(-lightDir, normal);
        spec = pow(max(dot(viewDir, reflectDir), 0.0), 8.0);
    }

    float d = distance(fs_in.vertex, spotLightPosition);

    float attenuation = 1.0 / (kc + kl * d + kq * (d * d));
    
    vec3 diffuseLightColor1 = vec3(0.0);
    
    if(enableSpotLight1)
    {
      diffuseLightColor1 = computeSpotLight(lightDir, spotLightDirection1, spotLightColor1);
    }

    vec3 diffuseLightColor2 = vec3(0.0);

    if(enableSpotLight2)
    {
      diffuseLightColor2 = computeSpotLight(lightDir, spotLightDirection2, spotLightColor2);
    }

    vec3 diffuseLightColor3 = vec3(0.0);

    if(enableSpotLight3)
    {
      diffuseLightColor3=computeSpotLight(lightDir,spotLightDirection3,spotLightColor3);
    }

    vec3 specular = vec3(0.3) * spec; // assuming bright white light color

    FragColor = vec4(ambient + (diffuse + diffuse2 + (diffuseLightColor1 + diffuseLightColor2 +  diffuseLightColor3 ) + specular) * attenuation, 1.0);
}
