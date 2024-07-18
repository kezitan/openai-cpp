 #include "openai.hpp"

#include <iostream>

int main() {
    openai::start("sk-on-Jo5FAGExsug1vrAvXCQ","",true,"https://agino.me/");
    std::string input;
    std::string end="end";
    
    while(true)
    {
        std::getline(std::cin, input);
        if(input==end)break;
        nlohmann::json chatRequest = {
    {"input",input}
};
    try {
            auto  moderation = openai::moderation().create(chatRequest);
            std::cout << "AI: ";
            if (moderation.contains("results") && moderation["results"].size() > 0) {
                std::cout << moderation["results"][0]["categories"] <<std::endl;
            } else {
                std::cout << "未能获取到有效回复，请稍后再试。" << std::endl;
            }
        } 
        catch (const std::exception& e) {
            std::cerr << "与 OpenAI 交互时发生错误: " << e.what() << std::endl;
        }
    }
        return 0;
    }
 
 
