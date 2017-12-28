#pragma once


#ifndef LAB471_CAMERA_H_INCLUDED
#define LAB471_CAMERA_H_INCLUDED

#include <stack>
#include <memory>

#include "glm/glm.hpp"
#include "glm/vec4.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"





class camera
{
public:
	glm::vec3 pos;
	glm::vec3 rot;
	glm::vec3 target;
	glm::vec3 direction;
	glm::vec3 right;
	glm::vec3 up;
	glm::vec3 front;
	glm::mat4 view;

	int w, a, s, d, shift;

	int kl, kr, ku, kd;

	float deltaTime;
	float lastFrame;
	float xpos;
	float ypos;
	float lastX;
	float lastY;
	float yaw;
	float pitch;


	camera()
	{
		w = a = s = d = 0;
		kl = kr = ku = kd = 0;
		shift = 0;
		deltaTime = 0.0f;
		lastFrame = 0.0f;

		pos = glm::vec3(0.0f,0.0f,3.0f);

		rot = glm::vec3(0, 0, 0);
		target = glm::vec3(0.0f, 0.0f, 0.0f);
		direction = glm::normalize(pos - target);
		glm::vec3 tup = glm::vec3(0.0f, 1.0f, 0.0f);
		right = glm::normalize(glm::cross(tup, direction));

		up = glm::vec3(0.0f,1.0f,0.0f);

		front = glm::vec3(0.0f, 0.0f, -1.0f);

		view = glm::lookAt(pos,pos + front,up);
		lastX = 0;
		lastY = 0;
		xpos = 0;
		ypos = 0;
		
	}
	glm::mat4 process()
	{
		if (kl == 1)
		{
			xpos -= 1;
		}
		if (kr == 1)
		{
			xpos += 1;
		}
		if (ku == 1)
		{
			ypos -= 1;
		}
		if (kd == 1)
		{
			ypos += 1;
		}

		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		float xoffset = xpos - lastX;
		float yoffset = lastY - ypos;
		lastX = xpos; lastY = ypos;
		float sensitivity = 1.5f;
		xoffset *= sensitivity;
		yoffset *= sensitivity;

		yaw += xoffset;
		pitch += yoffset;

		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;

		glm::vec3 f;
		f.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
		f.y = sin(glm::radians(pitch));
		f.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));
		front = glm::normalize(f);

		float speed = (15+shift) * deltaTime;

		if (w == 1)
			pos += speed * front;
		if (s == 1)
			pos -= speed * front;
		if (a == 1)
			pos -= glm::normalize(glm::cross(front, up)) * speed;
		if (d == 1)
			pos += glm::normalize(glm::cross(front, up)) * speed;

		view = glm::lookAt(pos, pos + front, up);
		return view;
	}
};








#endif // LAB471_CAMERA_H_INCLUDED