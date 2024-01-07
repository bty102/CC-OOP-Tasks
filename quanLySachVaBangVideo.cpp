#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
class Media {
    public:
        Media() {
            name = "";
            price = 0;
        }
        Media(std::string name, int price) {
            this->name = name;
            this->price = price;
        }
        void setName(std::string name) {
            this->name = name;
        }
        std::string getName() {
            return name;
        }
        void setPrice(int price) {
            this->price = price;
        }
        int getPrice() {
            return price;
        }
        void input() {
            std::cout << "Name: ";
            //std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Price(dong): ";
            std::cin >> price;
        }
        void output() {
            std::cout << "Name: " << name << "\n";
            std::cout << "Price: " << price << "(dong)\n";
        }
    private:
        std::string name;
        int price;//dong
};
class Book : public Media {
    public:
        Book() : Media() {
            numOfPage = 0;
            author = "";
        }
        Book(std::string name, int price, int numOfPage, std::string author) : Media(name, price){
            this->numOfPage = numOfPage;
            this->author = author;
        }
        void input() {
            Media::input();
            std::cout << "Number of page: ";
            std::cin >> numOfPage;
            std::cout << "Name of author: ";
            std::cin.ignore();
            std::getline(std::cin, author);
        }
        void output() {
            Media::output();
            std::cout << "Number of page: " << numOfPage << "\n";
            std::cout << "Author: " << author << "\n";
        }
        bool operator >(Book &b) {
            if(this->numOfPage > b.numOfPage)
                return true;
            return false;
        }
        void setNumOfPage(int numOfPage) {
            this->numOfPage = numOfPage;
        }
        int getNumOfPage() {
            return numOfPage;
        }
        void setAuthor(std::string author) {
            this->author = author;
        }
        std::string getAuthor() {
            return author;
        }
    private:
        int numOfPage;
        std::string author;
};
class Video : public Media {
    public:
        Video() : Media() {
            time = 0;
            producer = "";
        }
        Video(std::string name, int price, double time, std::string producer) : Media(name, price){
            this->time = time;
            this->producer = producer;
        }
        void input() {
            Media::input();
            std::cout << "Amount of time(s): ";
            std::cin >> time;
            std::cout << "Producer: ";
            std::cin.ignore();
            std::getline(std::cin, producer);
        }
        void output() {
            Media::output();
            std::cout << "Amount of time: " << time << "(s)\n";
            std::cout << "producer: " << producer << "\n";
        }
        bool operator >(Video &v) {
            if(this->time > v.time)
                return true;
            return false;
        }
        void setTime(double time) {
            this->time = time;
        }
        double getTime() {
            return time;
        }
        void setProducer(std::string producer) {
            this->producer = producer;
        }
        std::string getProducer() {
            return producer;
        }
    private:
        double time;//thoi luong(s)
        std::string producer;//nha san xuat
};
void setInformationOfBooks(std::vector<Book> &book);
void setInformationOfVideos(std::vector<Video> &video);
void showInformationOfBooks(std::vector<Book> &book);
void showInformationOfVideos(std::vector<Video> &video);
bool cmpBook(Book a, Book b);
bool cmpVideo(Video a, Video b);
int main() {
    int numOfBook, numOfVideo;
    std::cout << "Number of book: ";
    std::cin >> numOfBook;
    std::cout << "Number of video: ";
    std::cin >> numOfVideo;
    std::cin.ignore();
    std::vector<Book> book(numOfBook);
    std::vector<Video> video(numOfVideo);
    setInformationOfBooks(book);
    setInformationOfVideos(video);
    showInformationOfBooks(book);
    showInformationOfVideos(video);
    std::sort(book.begin(), book.end(), cmpBook);
    std::sort(video.begin(), video.end(), cmpVideo);
    std::cout << ">>>After sorted:\n";
    showInformationOfBooks(book);
    showInformationOfVideos(video);
    return 0;
}
void setInformationOfBooks(std::vector<Book> &book) {
    std::cout << ">>>Information of books:\n";
    for(int i = 0; i <= book.size()-1; i++) {
        book[i].input();
    }
}
void setInformationOfVideos(std::vector<Video> &video) {
    std::cout << ">>>Information of videos:\n";
    for(int i = 0; i <= video.size()-1; i++) {
        video[i].input();
    }
}
void showInformationOfBooks(std::vector<Book> &book) {
    std::cout << ">>>Information of books:\n";
    for(int i = 0; i <= book.size()-1; i++) {
        book[i].output();
    }
}
void showInformationOfVideos(std::vector<Video> &video) {
    std::cout << ">>>Information of videos:\n";
    for(int i = 0; i <= video.size()-1; i++) {
        video[i].output();
    }
}
bool cmpBook(Book a, Book b) {
    //return a.getNumOfPage() < b.getNumOfPage();
    return b > a;
}
bool cmpVideo(Video a, Video b) {
    //return a.getTime() < b.getTime();
    return b > a;
}
