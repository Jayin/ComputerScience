/**
 * C语言词法分析
 */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <set>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

void get_digits(); // 读取并识别实数
bool get_comments(); // 读取并识别注释
int table_insert();// 将标识符插入符号表

bool notEnd = true;  // 循环标志变量
int state  = 0;     // 有限自动机状态变量
int line   = 0;  //  行数
int column = 0;  //  列数
int cnt_word = 0; // 单词数
int cnt_char = 0;  // 字符数

ifstream infile;
ofstream outfile;
ofstream tablefile;       // 输出符号表文件
vector<string> table;     // 符号表
string ifile, ofile, tfile; // 输入输出文件名
string buffer, token;     // 缓冲区、标记
string::iterator forward_node = buffer.end();  // 缓冲区前向指针

//关键字
string words[] = { "auto", "double", "int", "struct", "break", "else", "long",
		"switch", "case", "enum", "register", "typedef", "char", "extern",
		"return", "union", "const", "float", "short", "unsigned", "continue",
		"for", "signed", "void", "default", "goto", "sizeof", "volatile", "do",
		"if", "static", "while" };

int main() {
	set<string> keywords(words, words + 32);    // 关键字集合
	char C;

	cout << "输入源文件（回车默认使用in.c）：" << endl;
	getline(cin, ifile);
	if (ifile == "") {
		ifile = "in.c";               // 回车默认
	}
	infile.open(ifile.c_str());
	if (!infile) {
		cout << "无法打开源文件！" << endl;
		return -1;
	}

	cout << "输出目标文件（回车默认使用out.txt）：" << endl;
	getline(cin, ofile);
	if (ofile == "") {
		ofile = "out.txt";    // 回车默认
	}
	outfile.open(ofile.c_str());
	if (!outfile) {
		cout << "无法创建目标文件！" << endl;
		return -1;
	}

	cout << "输出符号表（回车默认使用table.txt）：" << endl;
	getline(cin, tfile);
	if (tfile == "") {
		tfile = "table.txt";
	}
	tablefile.open(tfile.c_str());
	if (!tablefile) {
		cout << "无法创建符号表！" << endl;
		return -1;
	}

	while (true) {
		if (forward_node == buffer.end()) {              // 读到行末
			if (getline(infile, buffer, '\n')) {    // 读到错误或EOF则返回false
				++line;                             // 读取新行
				cnt_char += column;                 // 每次换行前加上当前行的字符数
				forward_node = buffer.begin();           // 重置前向指针
				column = 0;                         // 每次新行列数清零
			} else {
				cnt_char += column;
				infile.close();
				outfile.close();
				int i = 1;                          // 将符号表写入文件
				for (vector<string>::iterator it = table.begin();
						it != table.end(); ++it) {
					tablefile <<  i++ << "\t" << *it << endl;
				}
				tablefile.close();
				cout << "总行数：" << line << endl;
				cout << "单词个数：" << cnt_word << endl;
				cout << "字符个数：" << cnt_char << endl;
				return 0;
			}
		}

		while ((forward_node != buffer.end()) && isspace(*forward_node)) { // 未读到缓冲区结束，则一直读到非空字符
			++forward_node;
			++column;
		}

		if (forward_node != buffer.end()) {                          // 未读到缓冲区末尾
			token = "";
			C = *forward_node;
			switch (C) {
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '_':
				token.append(1, C);
				++forward_node;
				++column;
				while ((forward_node != buffer.end())
						&& (isalnum(*forward_node) || *forward_node == '_')) { // 合法标识符可包含下划线
					token.append(1, *forward_node++);
					++column;
				}
				if (keywords.count(token) == 0) {                   // 查关键字表
					outfile << "< ID," << table_insert() << " >" << endl;
				} else {
					outfile << "< key," << token << " >" << endl;
				}
				++cnt_word;
				break;

			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				token.append(1, C);
				state = 1;
				++forward_node;
				++column;
				get_digits();                                     // 读取无符号实数剩余部分
				outfile << "< num," << token << " >" << endl;
				notEnd = true;
				state = 0;
				++cnt_word;
				break;

			case '+':
				token.append(1, C);
				++forward_node;
				++column;
				if (forward_node == buffer.end()) {
					outfile << "< arith-op," << token << " >" << endl;
				} else {
					if (*forward_node == '+') {
						token.append(1, *forward_node++);
						++column;
						outfile << "< arith-op," << token << " >" << endl;
					} else if (*forward_node == '=') {
						token.append(1, *forward_node++);
						++column;
						outfile << "< asgn-op," << token << " >" << endl;
					} else {
						outfile << "< arith-op," << token << " >" << endl;
					}
				}
				++cnt_word;
				break;

			case '-':
				token.append(1, C);
				++forward_node;
				++column;
				if (forward_node == buffer.end()) {
					outfile << "< arith-op," << token << " >" << endl;
				} else {
					if (*forward_node == '-') {
						token.append(1, *forward_node++);
						++column;
						outfile << "< arith-op," << token << " >" << endl;
					} else if (*forward_node == '=') {
						token.append(1, *forward_node++);
						++column;
						outfile << "< asgn-op," << token << " >" << endl;
					} else if (*forward_node == '>') {
						token.append(1, *forward_node++);
						++column;
						outfile << "< others," << token << " >" << endl;
					} else {
						outfile << "< arith-op," << token << " > " << endl;
					}
				}
				++cnt_word;
				break;

			case '*':
				token.append(1, C);
				++forward_node;
				++column;
				if (forward_node == buffer.end()) {
					outfile << "< arith-op," << token << " >" << endl;
				} else {
					if (*forward_node == '=') {
						token.append(1, *forward_node++);
						++column;
						outfile << "< asgn-op," << token << " >" << endl;
					} else {
						outfile << "< arith-op," << token << " >" << endl;
					}
				}
				++cnt_word;
				break;

			case '/':
				token.append(1, C);
				++forward_node;
				++column;
				if (forward_node == buffer.end()) {
					outfile << "< arith-op," << token << " >" << endl;   // 行末除号
					++cnt_word;
				} else {
					if (*forward_node == '=') {                        // 除法复合赋值 /=
						token.append(1, *forward_node++);
						++column;
						outfile << "< asgn-op," << token << " >" << endl;
						++cnt_word;
					} else if (*forward_node == '/') {              // 单行注释，读到行末
						token.append(1, *forward_node++);
						++column;
						while (forward_node != buffer.end()) {
							token.append(1, *forward_node++);
							++column;
						}
						outfile << "< comments," << token<<"- >" << endl;
					} else if (*forward_node == '*') {               // 多行注释可以换行
						token.append(1, *forward_node++);
						++column;
						int ret = get_comments();
						if (ret) {
							outfile << "< comments," << token << "- >" << endl;
						} else {
							infile.close();
							outfile.close();
							int i = 1;
							for (vector<string>::iterator it = table.begin();
									it != table.end(); ++it) {
								tablefile << left << i++ << "\t" << *it << endl;
							}
							tablefile.close();
							cout << "语句行数：" << line << endl;
							cout << "单词个数：" << cnt_word << endl;
							cout << "字符个数：" << cnt_char << endl;
							return 0;
						}
					} else {                                   // 除号后是其他字符，为单个除号
						outfile << "< arith-op," << token << " >" << endl;
						++cnt_word;
					}
				}
				break;

			case '%':
				token.append(1, C);
				++forward_node;
				++column;
				if (forward_node == buffer.end()) {
					outfile << "< arith-op," << token << " >" << endl;
				} else {
					if (*forward_node == '=') {
						token.append(1, *forward_node++);
						++column;
						outfile << "< asgn-op," << token << " >" << endl;
					} else {
						outfile << "< arith-op," << token << " >" << endl;
					}
				}
				++cnt_word;
				break;

			case '&':
				token.append(1, C);
				++forward_node;
				++column;
				if (forward_node == buffer.end()) {
					outfile << "< bit-op," << token << " >" << endl;
				} else {
					if (*forward_node == '=') {
						token.append(1, *forward_node++);
						++column;
						outfile << "< asgn-op," << token << " >" << endl;
					} else if (*forward_node == '&') {
						token.append(1, *forward_node++);
						++column;
						outfile << "< log-op," << token << " >" << endl;
					} else {
						outfile << "< bit-op," << token << " >" << endl;
					}
				}
				++cnt_word;
				break;

			case '|':
				token.append(1, C);
				++forward_node;
				++column;
				if (forward_node == buffer.end()) {
					outfile << "< bit-op," << token << " >" << endl;
				} else {
					if (*forward_node == '=') {
						token.append(1, *forward_node++);
						++column;
						outfile << "< asgn-op," << token << " >" << endl;
					} else if (*forward_node == '|') {
						token.append(1, *forward_node++);
						++column;
						outfile << "< log-op," << token << " >" << endl;
					} else {
						outfile << "< bit-op," << token << " >" << endl;
					}
				}
				++cnt_word;
				break;

			case '^':
				token.append(1, C);
				++forward_node;
				++column;
				if (forward_node == buffer.end()) {
					outfile << "< bit-op," << token << " >" << endl;
				} else {
					if (*forward_node == '=') {
						token.append(1, *forward_node++);
						++column;
						outfile << "< asgn-op," << token << " >" << endl;
					} else {
						outfile << "< bit-op," << token << " >" << endl;
					}
				}
				++cnt_word;
				break;

			case '~':
				token.append(1, C);
				++forward_node;
				++column;
				outfile << "< bit-op," << token << " >" << endl;
				++cnt_word;
				break;

			case '<':
				token.append(1, C);
				++forward_node;
				++column;
				if (forward_node == buffer.end()) {
					outfile << "< rel-op," << token << " >" << endl;
				} else {
					if (*forward_node == '=') {
						token.append(1, *forward_node++);
						++column;
						outfile << "< rel-op," << token << " >" << endl;
					} else if (*forward_node == '<') {
						token.append(1, *forward_node++);
						++column;
						outfile << "< bit-op," << token << " >" << endl;
					} else {
						outfile << "< rel-op," << token << " >" << endl;
					}
				}
				++cnt_word;
				break;

			case '=':
				token.append(1, C);
				++forward_node;
				++column;
				if (forward_node == buffer.end()) {
					outfile << "< asgn-op," << token << " >" << endl;
				} else {
					if (*forward_node == '=') {
						token.append(1, *forward_node++);
						++column;
						outfile << "< rel-op," << token << " >" << endl;
					} else {
						outfile << "< asgn-op," << token << " >" << endl;
					}
				}
				++cnt_word;
				break;

			case '>':
				token.append(1, C);
				++forward_node;
				++column;
				if (forward_node == buffer.end()) {
					outfile << "< rel-op," << token << " >" << endl;
				} else {
					if (*forward_node == '=') {
						token.append(1, *forward_node++);
						++column;
						outfile << "< rel-op," << token << " >" << endl;
					} else if (*forward_node == '>') {
						token.append(1, *forward_node++);
						++column;
						outfile << "< bit-op," << token << " >" << endl;
					} else {
						outfile << "< rel-op," << token << " >" << endl;
					}
				}
				++cnt_word;
				break;

			case '!':
				token.append(1, C);
				++forward_node;
				++column;
				if (forward_node == buffer.end()) {
					outfile << "< log-op," << token << " >" << endl;
				} else {
					if (*forward_node == '=') {
						token.append(1, *forward_node++);
						++column;
						outfile << "< rel-op," << token << " >" << endl;
					} else {
						outfile << "< log-op," << token << " >" << endl;
					}
				}
				++cnt_word;
				break;

			case '\"':
				token.append(1, C);
				++forward_node;
				++column;
				while (true) {
					while ((forward_node != buffer.end())
							&& (*forward_node != '\"')) {
						token.append(1, *forward_node++);
						++column;
						if (*(forward_node - 1) == '\\') {    // 如果读到'\'则后面字符为转义
							if (forward_node == buffer.end())
								break;
							else {
								token.append(1, *forward_node++);     // 多读入一个字符
								++column;
							}
						}
					}
					if (forward_node == buffer.end()) {
						outfile << "< Error(" << line << "," << column
								<< "): missing terminating \" character >"
								<< endl; //error();
						break;
					} else {
						token.append(1, *forward_node++);
						++column;
						outfile << "< string," << token << " >" << endl;
						break;
					}
				}
				++cnt_word;
				break;

			case '\'':
				token.append(1, C);
				++forward_node;
				++column;
				while ((forward_node != buffer.end()) && (*forward_node != '\'')) {
					token.append(1, *forward_node++);
					++column;
					if (*(forward_node - 1) == '\\') {        // 如果读到'\'则后面字符为转义
						if (forward_node == buffer.end())
							break;
						else {
							token.append(1, *forward_node++);      // 多读入一个字符
							++column;
						}
					}
				}
				if (forward_node == buffer.end()) {
					outfile << "< Error(" << line << "," << column
							<< "): missing terminating \' character >" << endl; //error();
				} else {
					token.append(1, *forward_node++);
					++column;
					outfile << "< char," << "- >" << endl;
				}
				++cnt_word;
				break;

			case '.':
				token.append(1, C);
				++forward_node;
				++column;
				if ((forward_node != buffer.end()) && isdigit(*forward_node)) { // 如果小数点后为数字，则转入实数识别
					token.append(1, *forward_node++);
					++column;
					state = 23;
					get_digits();
					notEnd = true;
					state = 0;
					outfile << "< num," << token << " >" << endl;
					++cnt_word;
					break;
				}
				outfile << "< others," << token << " >" << endl;
				++cnt_word;
				break;

			case '#':
			case '{':
			case '}':
			case '[':
			case ']':
			case '(':
			case ')':
			case '?':
			case ':':
			case ',':
			case ';':
			case '\\':
				token.append(1, C);
				++forward_node;
				++column;
				outfile << "< others," << token << " >" << endl;
				++cnt_word;
				break;

			default:
				++forward_node;
				++column;
				outfile << "< Error(" << line << "," << column
						<< "): invalid character >" << endl; //error();
				break;
			}    // end of switch
		}    // end of if
	}    // end of while
	return -1;
}

int table_insert() {
	vector<string>::iterator it = find(table.begin(), table.end(), token);
	if (it == table.end()) {
		table.push_back(token);
		it = find(table.begin(), table.end(), token);
	}
	return distance(table.begin(), it) + 1;
}

void get_digits()                                            // 读取实数，包含E/e指数
{
	while ((forward_node != buffer.end()) && notEnd) {
		switch (state) {
		case 1:
			if (*forward_node == '.') {
				token.append(1, *forward_node++);
				++column;
				state = 23;
			} else if (*forward_node == 'E' || *forward_node == 'e') {
				token.append(1, *forward_node++);
				++column;
				state = 4;
			} else if (isdigit(*forward_node)) {
				token.append(1, *forward_node++);
				++column;
				state = 1;
			} else {
				notEnd = false;                              // 识别结束
			}
			break;
		case 23:
			if (*forward_node == 'E' || *forward_node == 'e') {
				token.append(1, *forward_node++);
				++column;
				state = 4;
			} else if (isdigit(*forward_node)) {
				token.append(1, *forward_node++);
				++column;
				state = 23;
			} else {
				notEnd = false;
			}
			break;
		case 4:
			if (*forward_node == '+' || *forward_node == '-') {
				token.append(1, *forward_node++);
				++column;
				state = 6;
			} else if (isdigit(*forward_node)) {
				token.append(1, *forward_node++);
				++column;
				state = 5;
			} else {
				outfile << "< Error(" << line << "," << column
						<< "): exponent has no digits >" << endl;     //error();
				notEnd = false;
			}
			break;
		case 5:
			if (isdigit(*forward_node)) {
				token.append(1, *forward_node++);
				++column;
				state = 5;
			} else {
				notEnd = false;
			}
			break;
		case 6:
			if (isdigit(*forward_node)) {
				token.append(1, *forward_node++);
				++column;
				state = 5;
			} else {
				outfile << "< Error(" << line << "," << column
						<< "): exponent has no digits >" << endl;     //error();
				notEnd = false;
			}
			break;
		default:
			break;
		}
	}
}

bool get_comments() {
	while (true) {
		while ((forward_node != buffer.end()) && (*forward_node != '*')) {
			token.append(1, *forward_node++);
			++column;
		}
		if (forward_node == buffer.end()) {                      // 一行注释结束，继续下一行
			if (getline(infile, buffer, '\n')) {             // 读到错误或EOF则返回false
				++line;
				forward_node = buffer.begin();
				column = 1;
				continue;
			} else {
				return false;
			}
		} else {                                                 // 读到注释结束符的星号
			token.append(1, *forward_node++);
			++column;
			if (forward_node == buffer.end()) {         // 若 '*/' 被换行分开，则继续读取下一行
				continue;
			} else if (*forward_node == '/') {                        // 注释结束符ok
				token.append(1, *forward_node++);
				++column;
				return true;
			} else {                                         // 星号后是其他字符，仍继续读取注释
				continue;
			}
		}
	}
}
