/*************************************************************************
> File Name       : 13.34.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月25日  14时26分08秒
************************************************************************/

// 练习13.34、13.36、13.37

#include <string>
#include <set>
#include <iostream>

class Folder;

class Message
{
    friend class Folder;
    friend void swap(Message &lhs, Message &rhs);

private:
    std::string m_contents;
    std::set<Folder *> m_folder;

    void add_to_Folder(const Message &theMsg)
    {
        for (auto f : theMsg.m_folder)
            f->addMsg(this);
    }
    void remove_from_Folders()
    {
        for (auto f : m_folder)
            f->remMsg(this);

        m_folder.clear();
    }

    void addFldr(Folder *thePFolder) { m_folder.insert(thePFolder); }
    void remFldr(Folder *thePFolder) { m_folder.erase(thePFolder); }

public:
    explicit Message(const std::string &str = " ") : m_contents(str) {}
    Message(const Message &theMsg) : m_contents(theMsg.m_contents), m_folder(theMsg.m_folder) { add_to_Folder(theMsg); }
    Message &operator=(const Message &theMsg)
    {
        remove_from_Folders();
        m_contents = theMsg.m_contents;
        m_folder = theMsg.m_folder;
        add_to_Folder(theMsg);
        return *this;
    }
    ~Message() { remove_from_Folders(); }
    void save(Folder &theFolder)
    {
        m_folder.insert(&theFolder);
        theFolder.addMsg(this);
    }
    void remove(Folder &theFolder)
    {
        m_folder.erase(&theFolder);
        theFolder.remMsg(this);
    }

    void print() { std::cout << m_contents << std::endl; }
};

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    lhs.remove_from_Folders();
    rhs.remove_from_Folders();

    swap(lhs.m_folder, rhs.m_folder);
    swap(lhs.m_contents, rhs.m_contents);

    lhs.add_to_Folder(lhs);
    rhs.add_to_Folder(rhs);
}

class Folder
{
    friend class Message;
    friend void swap(Folder &lhs, Folder &rhs);

private:
    std::set<Message *> m_messages;

    void add_to_Message(const Folder &theFolder)
    {
        for (auto m : theFolder.m_messages)
            m->addFldr(this);
    }

    void remove_from_Message()
    {
        for (auto m : m_messages)
            m->remFldr(this);
    }

    void addMsg(Message *thePMessage) { m_messages.insert(thePMessage); }
    void remMsg(Message *thePMessage) { m_messages.insert(thePMessage); }

public:
    Folder() = default;
    Folder(const Folder &theFolder) : m_messages(theFolder.m_messages) { add_to_Message(theFolder); }
    Folder &operator=(const Folder &theFolder)
    {
        remove_from_Message();
        m_messages = theFolder.m_messages;

        add_to_Message(theFolder);
        return *this;
    }
    ~Folder() { remove_from_Message(); }

    void print()
    {
        for (auto m : m_messages)
            std::cout << m->m_contents << " ";
        std::cout << std::endl;
    }
};
void swap(Folder &lhs, Folder &rhs)
{
    using std::swap;
    lhs.remove_from_Message();
    rhs.remove_from_Message();

    swap(lhs.m_messages, rhs.m_messages);

    lhs.add_to_Message(lhs);
    rhs.add_to_Message(rhs);
}
