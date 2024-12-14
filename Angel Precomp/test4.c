```alias `MyFunc` is `library::subsection::MyFunc`;
alias `AnotherFN` is `library::subsection::AnotherFN`;

alias `Message` is `angel::msg::Message`;```//Comment

#include<angel/message>

int main() {
	`Message` msg = `MyFunc`("a message");
	
	printf(
		"%s\n%d", 
		`MyFunc`,
		msg@`AnotherFN`()
	);
	return 0;
}
