//
// Created by Liza on 3/13/2023.
//

#ifndef OPENGL_PRJ_SHADER_H
#define OPENGL_PRJ_SHADER_H

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <memory>
#include "Texture.h"

class Shader
{
public:
    enum ShaderType{
        eAxes,
        eBoxDemo,
        eMesh,
        // Coord + color as input
        eCustom
    };

public:
    unsigned int ID;
    static Shader& instance(ShaderType type);
public:
    //Shader(const char* vertexPath, const char* fragmentPath);
    Shader(const std::string& vertexPath, const std::string &fragmentPath);

    ~Shader();

    void use() const { glUseProgram(ID); }

    void setBool(const std::string& name, bool value) const{
        glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value); }

    void setInt(const std::string& name, int value) const{
        glUniform1i(glGetUniformLocation(ID, name.c_str()), value); }

    void setFloat(const std::string& name, float value) const{
        glUniform1f(glGetUniformLocation(ID, name.c_str()), value); }

    void setVec2(const std::string& name, const glm::vec2& value) const{
        glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]); }

    void setVec2(const std::string& name, float x, float y) const{
        glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y); }

    void setVec3(const std::string& name, const glm::vec3& value) const{
        glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]); }

    void setVec3(const std::string& name, float x, float y, float z) const{
        glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);}

    void setVec4(const std::string& name, const glm::vec4& value) const{
        glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);}

    void setVec4(const std::string& name, float x, float y, float z, float w) const{
        glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w);}

    void setMat2(const std::string& name, const glm::mat2& mat) const{
        glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);}

    void setMat3(const std::string& name, const glm::mat3& mat) const{
        glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);}

    void setMat4(const std::string& name, const glm::mat4& mat) const{
        glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);}

        void setTexture(const std::string& name, int num, const Texture& tex, GLenum slot = GL_TEXTURE0) const {
            setInt(name, 0);
            tex.bind(slot);
    }

private:

    void checkCompileErrors(GLuint shader, std::string type);
};

std::string make_path(char* dir, char* fname);

#endif //OPENGL_PRJ_SHADER_H
