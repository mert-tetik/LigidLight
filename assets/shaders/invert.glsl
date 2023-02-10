#version 330 core

#include <flutter/runtime_effect.glsl>

uniform sampler2D uTexture;

out vec4 fragColor;

void main(){
    fragColor = texture2D(uTexture,FlutterFragCoord().xy);    
}