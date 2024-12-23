//
// Created by Shivam on 23/12/24.
//

#ifndef TASK_H
#define TASK_H
#include <chrono>
#include <string>
using namespace std;

class Task {
    private:
        int id;
        string description;
        string status;
        string created_at;
        string updated_at;

    public:
        Task(int id, const string& description, const string& status, const string& created_at, const string& updated_at);
        int get_id() const;
        string get_description() const;
        string get_status() const;
        string get_created_at() const;
        string get_updated_at() const;

        void set_id(int id);
        void set_description(const string& description);
        void set_status(const string& status);
        void set_created_at(const string& created_at);
        void set_updated_at(const string& updated_at);

        void display_task() const;
};


#endif //TASK_H
