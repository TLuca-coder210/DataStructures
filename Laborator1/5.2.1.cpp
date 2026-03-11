class vectorClass{
    int capacity, current;
    int *arr;
    public:
        vectorClass(){
            arr = new int[1];
            capacity = 1;
            current = 0;
        }
        ~vectorClass(){
            delete[] arr;
        }
        void push_back(const int number){
            if(current == capacity){
                int *temp = new int[2 * capacity];
                for(int i = 0; i < capacity; i++){
                    temp[i] = arr[i];
                }
                delete[] arr;
                capacity *= 2;
                arr = temp;
            }
            arr[current] = number;
            current++;
        }
        vectorClass operator=(const vectorClass &other) {
            this->capacity = other.capacity;
            this->current = other.current;
            this->arr = other.arr;
        }
        void swap(int first, int second){
            swap(arr[first], arr[second]);
        }
        int get_size() const {
            return current;
        }
        void pop_back(){
            if(current > 0){
                current--;
            }
        }
        int operator[](int index){
            if(index < current){
                return arr[index];
            }
            return -1;
        }
};
