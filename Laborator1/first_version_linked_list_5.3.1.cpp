struct Node{
    int value, position;
};
class LinkedList{
    vector<Node> nodes;
    int head, tail;
    public:
        LinkedList(){
            this->head = -1;
            this->tail = -1;
        }
        ~LinkedList(){
            head = -1;
            tail = -1;
        }
        LinkedList(const LinkedList &argument){
            this->head = argument.head;
            this->nodes = argument.nodes;
        }
        void insertHead(const int val){
            Node element;
            element.value = val;
            element.position = this->head;
            nodes.push_back(element);
            if(this->head == -1){
                this->tail = nodes.size() - 1;
            }
            this->head = nodes.size() - 1;
        }
        void eraseHead(){
            if(this->head == -1){
                cout << "List is empty" << '\n';
            }
            int pos = nodes[this->head].position;
            this->head = pos;
        }
        void insertTail(const int val){
            Node element;
            element.value = val;
            element.position = this->tail;
            nodes.push_back(element);
            if(this->head == -1){
                this->head = nodes.size() - 1;
            }
            this->tail = nodes.size() - 1;
        }
        void eraseTail(){
            if(this->tail == -1){
                cout << "List is empty" << '\n';
            }
            if(this->head == -1){
                return;
            }
            if(this->head == this->tail){
                //lista are un singur element
                this->head = -1;
                this->tail = -1;
                return;
            }
            int curr = this->head;
            while(nodes[curr].position != this->tail){
                curr = nodes[curr].position;
            }
            nodes[curr].position = -1;
            this->tail = curr;
        }
        Node FindNodeByValue(const int val){
            int curr = this->head;
            while(nodes[curr].value != val){
                curr = nodes[curr].position;
            }
            return {(curr, val)};
        }
        Node FindNodeByIndex(const int index){
            int curr = this->head;
            if(curr == index){
                return {(curr, nodes[curr].value)};
            }
            while(nodes[curr].position != index){
                curr = nodes[curr].position;
            }
            return {(curr, nodes[curr].value)};
        }
        void InsertAtRandom(const int val){
            int index = int(rand()) / (nodes.size() + 1), counter = 0, curr = this->head, last = this->head;
            if(index == 1){
                Node element;
                element.position = nodes[this->head].position;
                element.value = val;
                nodes.push_back(element);
                nodes[this->head].position = nodes.size() - 1;
            }
            while(counter != index){
                last = curr;
                curr = nodes[curr].position;
                counter++;
            }
            Node element;
            element.position = curr;
            element.value = val;
            nodes.push_back(element);
            if(index == 0){
                this->head = nodes.size() - 1;
            }
            else{
                nodes[last].position = nodes.size() - 1;
            }
        }  
        void EraseAtRandom(){
            int index = int(rand()) / nodes.size(), counter = 0, curr = this->head, last = -1;
            while(counter != index){
                last = curr;
                curr = nodes[curr].position;
            }
            if(last == -1){
                this->head = nodes[this->head].position;
                return;
            }
            nodes[last].position = nodes[curr].position;
        }

};
