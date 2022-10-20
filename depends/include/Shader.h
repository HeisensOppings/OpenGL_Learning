#pragma once

#include <string>
#include <unordered_map>

struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};

class Shader
{
    private:
        unsigned int m_RendererID;
        std::string m_FilePath;
        std::unordered_map<std::string, int> m_UniformLoationCache;

    public:
        Shader(const std::string& filepath);
        ~Shader();

        void Bind() const;
        void Unbind() const;

        //Set Uniforms
        void SetUniform4f(const std::string& name, float f0, float f1, float f2, float f3);
        void SetUnifoem1f(const std::string& name, float value);
        void SetUnifoem1i(const std::string& name, int value);

    private:
        int GetUniformLocation(const std::string& name);
        struct ShaderProgramSource ParseShader(const std::string& source);
        unsigned int CompileShader(unsigned int type, const std::string& source);
        unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
};