#include <iostream>
using namespace std;
#include "nlohmann/json.hpp"
#include "openai.hpp"  // 包含 OpenAI 头文件
using namespace std;

class Chatbot {
private:
    std::string apiKey;
    // 其他可能需要的成员变量

public:
    Chatbot(const std::string& apiKey) : apiKey(apiKey) {}

    void chat(const std::string& userInput) {
        openai::start(apiKey,"",true,"https://agino.me/");

        nlohmann::json chatRequest = {
    {"model", "gpt-4o"},
    {"messages", {
        {
            {"role", "user"},
            {"content", userInput}
        }
    }}
};

        try {
            auto response = openai::chat().create(chatRequest);
            std::cout << "AI: ";
            if (response.contains("choices") && response["choices"].size() > 0) {
                std::cout << response["choices"][0]["message"]["content"] << std::endl;
            } else {
                std::cout << "未能获取到有效回复，请稍后再试。" << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "与 OpenAI 交互时发生错误: " << e.what() << std::endl;
        }
    }
};

int main() {
    std::string apiKey = "sk-0DITh75zrxk-8tM6mhckTA";  // 替换为您的实际 API 密钥
    Chatbot chatbot(apiKey);
 std::cout << "                                  " << endl;
 cout << "                                  " << endl;
 cout << "                                  " << endl;
 cout << "                                  " << endl;
 cout << "                                  ◢ █ █ █ █ █ █ █ █ █ █ █ █ ◣" << endl;
 cout << "                            　　　█ █ █ █ █ █ █ █ █ █ █ █ █ █　" << endl;
 cout << "                            　　　█ █　　　◥ █ █ ◤　　　█ █　" << endl;
 cout << "                            　◢ █ █ █　　　　◥ ◤　　　　█ █ ◣" << endl;
 cout << "                            　▊ ▎ █ █ ◣　　　　　　 　　◢ █ ▊ ▊" << endl;
 cout << "                            　▊ ▎ █ █ ◤　　●　 　●　　◥ █ ▊ ▊" << endl;
 cout << "                            　▊　█ █　　　　　　　　　　█ ▊ ▊" << endl;
 cout << "                            　◥ ▇ █ █　 ▊　　　　　　▊　█ ▇ ◤                     欢迎" << endl;             //欢迎界面
 cout << "                            　　　█ █　◥▆ ▄ ▄ ▄ ▄ ▆ ◤　█ ▊　　             ◢▇ ▇◣" << endl;
 cout << "                            ◢ █ █◥◥▆ ▅ ▄ ▂ ▂ ▂ ▂ ▄ ▅ ▆                  ◢█" << endl;
 cout << "                            █ ╳　　　　　　　　　　　　　╳ █　           ◢◤" << endl;
 cout << "                            ◥ █ ◣　　　˙　　　　　˙　◢ █ 　　      ◢◤　 " << endl;
 cout << "                            　　▊　　　　　　　　　　　　　▊　　　　   █" << endl;
 cout << "                            　　▊　　　　　　　　　　　　　▊　　　  ◢◤" << endl;
 cout << "                            　　▊　　　　　　⊕　　　　　　█ ▇ ▇ ▇ ◤　" << endl;
 cout << "                            　◢ █ ▇ ▆ ▆ ▆ ▅ ▅ ▅ ▅ ▆ ▆ ▆ ▇ █ " << endl;
 cout << "                            　▊　　　　　　　　             ▊　 　" << endl;


    std::string userInput;
    std::string userinput;
    std::string stop="stop";//中止切换
    std::string end="end";//终止
    std::string rebuild="重新";
    while (true) {
        std::cout << "您: ";
        std::getline(std::cin, userInput);
        if(userInput==end) break;
        else if(userInput==stop) userinput.clear();
        else if(userInput==rebuild) ;
        else userinput+=userInput;

        if (userInput.empty()) {
            std::cout << "输入不能为空，请重新输入。" << std::endl;
            continue;
        }
        chatbot.chat(userinput);
    }

    return 0;
}
