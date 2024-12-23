//
// Created by Shivam on 23/12/24.
//

#include "Task.h"
#include <iostream>
using namespace std;


Task::Task(int id, const string& description, const string& status, const string& created_at, const string& updated_at)
: id(id), description(description), status(status), created_at(created_at), updated_at(updated_at) {}

int Task::get_id() const
{
    return id;
}

string Task::get_description() const
{
    return description;
}

string Task::get_status() const
{
    return status;
}

string Task::get_created_at() const
{
    return created_at;
}

string Task::get_updated_at() const
{
    return updated_at;
}


void Task::set_id(int id)
{
    Task::id = id;
}

void Task::set_description(const string& description)
{
    Task::description = description;
}

void Task::set_status(const string& status)
{
    Task::status = status;
}

void Task::set_created_at(const string& created_at)
{
    Task::created_at = created_at;
}

void Task::set_updated_at(const string& updated_at)
{
    Task::updated_at = updated_at;
}

void Task::display_task() const
{
    cout << "Task id: " << Task::get_id()
         << "\nDescription: " << Task::get_description()
         << "\nStatus: " << Task::get_status()
         << "\nCreated At: " << Task::get_created_at()
         << "\nUpdated At: " << Task::get_updated_at() << endl;
}
