3  Implement a simple text editor. The editor initially contains an empty string, S.Perform Q  operations of the following 4 types:
⮚	append(W) - Append string W to the end of S.
⮚	delete (k)- Delete the last k characters of S.
⮚	print (k)- Print the k^th  character of  S.
⮚	undo() - Undo the last (not previously undone) operation of type 1 or 2, reverting  S to the state it was in prior to that operation.

  #include <iostream>
#include <stack>
#include <string>

class TextEditor {
private:
    std::string S;
    std::stack<std::pair<int, std::string>> history;

public:
    // Append string W to the end of S
    void append(const std::string& W) {
        history.push({1, W});
        S += W;
    }

    // Delete the last k characters of S
    void deleteChars(int k) {
        std::string deletedPart = S.substr(S.size() - k, k);
        history.push({2, deletedPart});
        S.erase(S.size() - k);
    }

    // Print the k-th character of S
    void print(int k) const {
        if (k > 0 && k <= S.size()) {
            std::cout << S[k - 1] << std::endl;
        } else {
            std::cerr << "Invalid position" << std::endl;
        }
    }

    // Undo the last operation of type 1 or 2
    void undo() {
        if (!history.empty()) {
            auto lastOperation = history.top();
            history.pop();

            if (lastOperation.first == 1) { // Undo append
                S.erase(S.size() - lastOperation.second.size());
            } else if (lastOperation.first == 2) { // Undo delete
                S += lastOperation.second;
            }
        }
    }
};

int main() {
    TextEditor editor;
    int Q;
    std::cin >> Q;

    for (int i = 0; i < Q; ++i) {
        int type;
        std::cin >> type;

        if (type == 1) { // append(W)
            std::string W;
            std::cin >> W;
            editor.append(W);
        } else if (type == 2) { // delete(k)
            int k;
            std::cin >> k;
            editor.deleteChars(k);
        } else if (type == 3) { // print(k)
            int k;
            std::cin >> k;
            editor.print(k);
        } else if (type == 4) { // undo()
            editor.undo();
        }
    }

    return 0;
}
