#include <iostream>
#include "nlohmann/json.hpp"
#include "openai.hpp"  // 包含 OpenAI 头文件
 std::string userInput;
 std::string userinput;
 int order;
 int out;
 char board[15][15];

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

nlohmann::json chatRequest1 = {
    {"input",userinput}
};

        try {
            auto response = openai::chat().create(chatRequest);
            if (response.contains("choices") && response["choices"].size() > 0) {
                std::cout << "AI: "<<std::endl;
                std::string s=(std::string)response["choices"][0]["message"]["content"];
                if(out==2)
                {
                    std::cout<< response["choices"][0]["message"]["content"] << std::endl;;
                }
                else if(out==1)
                {
                int a=0,b=0,found=0;
                for(int i=0;s[i];i++)
                {
                    if(s[i]>='0'&&s[i]<='9'&&found==0&&!(s[i+1]<='9'&&s[i+1]>='0'))
                    {
                        a=s[i]-'0';
                        found=1;
                    }
                    else if(s[i]>='0'&&s[i]<='9'&&found==0&&(s[i+1]<='9'&&s[i+1]>='0'))
                    {
                        a=(s[i]-'0')*10+(s[i+1]-'0');
                        found=1;
                    }
                    else if(s[i]>='0'&&s[i]<='9'&&found==1&&!(s[i+1]<='9'&&s[i+1]>='0'))
                    {
                        b=s[i]-'0';break;
                    }
                    else if(s[i]>='0'&&s[i]<='9'&&found==1&&(s[i+1]<='9'&&s[i+1]>='0'))
                    {
                        b=(s[i]-'0')*10+(s[i+1]-'0');break;
                    }
                }

                board[a-1][b-1]='x';
         for(int i=0;i<15;i++)//输出棋盘
         {
          for(int j=0;j<15;j++)
          std::cout<<board[i][j];
        std::cout<<std::endl;
        }  
                }
                userinput+="你已下的棋子的坐标：";
                userinput+=s;
            } else {
                std::cout << "未能获取到有效回复，请稍后再试。" << std::endl;
            }

        auto  moderation = openai::moderation().create(chatRequest1);
            if (moderation.contains("results") && moderation["results"].size() > 0) {
                if(moderation["results"][0]["categories"]["harassment"]==true||
                moderation["results"][0]["categories"]["harassment/threatening"]==true||
                moderation["results"][0]["categories"]["hate"]==true||
                moderation["results"][0]["categories"]["hate/threatening"]==true||
                moderation["results"][0]["categories"]["self-harm"]==true||
                moderation["results"][0]["categories"]["self-harm/instructions"]==true||
                moderation["results"][0]["categories"]["self-harm/intent"]==true||
                moderation["results"][0]["categories"]["sexual"]==true||
                moderation["results"][0]["categories"]["sexual/minors"]==true||
                moderation["results"][0]["categories"]["violence"]==true||
                moderation["results"][0]["categories"]["violence/graphic"]==true
                )
                {
        auto completion1 = openai::chat().create(R"(
    {
        "model": "gpt-4o",
        "messages": [{"role": "user", "content": "消解我的消极情绪"}],
        "max_tokens": 4096,
        "temperature": 0
    }
    )"_json); // Using user-defined (raw) string literals
   if (completion1.contains("choices") && completion1["choices"].size() > 0) {
                std::cout << completion1["choices"][0]["message"]["content"] << std::endl;
                }
            }
        }
        } catch (const std::exception& e) {
            std::cerr << "与 OpenAI 交互时发生错误: " << e.what() << std::endl;
        }
    }
};

int main() {
     for(int i=0;i<15;i++)
 {
    for(int j=0;j<15;j++)
    board[i][j]='.';
    //std::strcpy (board[i],"...............");
 }

 
 //std::cout<<board[i]<<std::endl;
    std::string apiKey = "sk-0DITh75zrxk-8tM6mhckTA";  // 替换为您的实际 API 密钥
    Chatbot chatbot(apiKey);
    std::string stop="结束这个话题";//中止切换
    std::string stop1="stop";//中止切换
    std::string end="end";//终止
    std::string rebuild="重新";
    std::cout<<"五子棋激活:1"<<std::endl;
    std::cout<<"智能对话激活:2"<<std::endl;
    std::cout<<"输入stop结束当前对话,开启新对话,输入end结束所有对话"<<std::endl;

   start:
   std::cout<<"请输入指令：";
    std::cin>>order;
    if(order==1)
    {
         for(int i=0;i<15;i++)
 {
  for(int j=0;j<15;j++)
 std::cout<<board[i][j];
 std::cout<<std::endl;
 }
        userInput="请和我在15*15的棋盘里下五子棋,每个位置坐标均用数字表示,如左上角坐标为(1,1),我输入的坐标你不能再用，你每次只需回答你所下的位置即可,我先走棋";
        out=2;
         chatbot.chat(userInput);
         userinput+=userInput;
         out=1;
         while(true)
         {
            std::getline(std::cin, userInput);
             if(userInput==end) break;
        else if(userInput==stop||userInput==stop1) {userinput.clear();goto start;}
        else if(userInput==rebuild) ;
        else 
        {
            userinput+="我已经下子的坐标(";
            userinput+=userInput;
            userinput+=")";
        }

        if (userInput.empty()) {
            std::cout << "输入不能为空，请重新输入。" << std::endl;
            continue;
        }
            int a,b;
            if(!(userInput[1]<='9'&&userInput[1]>='0'))
            a=userInput[0]-'0';
            else if(userInput[1]<='9'&&userInput[1]>='0')
            a=(userInput[0]-'0')*10+userInput[1]-'0';
            for(int i=1;userInput[i];i++)
            {
                if(userInput[i]>='0'&&userInput[i]<='9'&&!(userInput[i+1]<='9'&&userInput[i+1]>='0'))
                    {
                        b=userInput[i]-'0';break;
                    }
                    else if(userInput[i]>='0'&&userInput[i]<='9'&&(userInput[i+1]<='9'&&userInput[i+1]>='0'))
                    {
                        b=(userInput[i]-'0')*10+(userInput[i+1]-'0');break;
                    }
            }
            std::cout<<a<<" "<<b<<std::endl;
            board[a-1][b-1]='o';
            std::cout<<"你："<<std::endl;
             for(int i=0;i<15;i++)
 {
  for(int j=0;j<15;j++)
 std::cout<<board[i][j];
 std::cout<<std::endl;
 }
        
         chatbot.chat(userinput);
         }
    }
    else if(order==2)
    {
        out=2;
while (true) {
        std::cout << "您: ";
        std::getline(std::cin, userInput);
         if(userInput==end) break;
        else if(userInput==stop||userInput==stop1)  {userinput.clear();goto start;}
        else if(userInput==rebuild) ;
        else 
        {
            userinput+=userInput;
        }

        if (userInput.empty()) {
            std::cout << "输入不能为空，请重新输入。" << std::endl;
            continue;
        }
        chatbot.chat(userinput);
    }
    
      
    }

    return 0;
}