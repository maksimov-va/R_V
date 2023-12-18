#include "pch.h"
#include "par_title_t.h"
class realise_par_title :public par_title_t {
public:
    unsigned char list_id;//������������� ����� ����������
    const char* name;//��������

    
    realise_par_title(const unsigned char list_id, const char* name) {
        this->list_id = list_id;
        this->name = name;
    }



    /*!
     * ���������� ������������� ������ ����������
     * @return ������������� ������ ����������
     */
    virtual unsigned char get_list_id() const override
    {
        return list_id;
    }

    virtual const char* get_text_id() const override
    {
        return nullptr;
    }

    /*!
    * ���������� ��������
    * @return ��������
    */
    virtual const char* get_name() const override
    {
        return name;
    }

    virtual bool get_valid() const override
    {
        return false;
    }


    virtual void set_valid(const bool valid) override
    {
    }

    virtual par_status_t get_status() const override
    {
        return par_status_t();
    }

    virtual void set_status(const par_status_t status) override
    {
    }

    virtual bool get_out_of_range() const override
    {
        return false;
    }

    virtual void set_out_of_range(const bool out_of_range) override
    {

    }

    virtual void reset() override
    {
    }

    virtual void reset_status() override
    {
    }

    virtual void add_change_handler(void(*handler)(par_t*, const par_change_flags_t)) override
    {
    }

    virtual void remove_change_handler(void(*handler)(par_t*, const par_change_flags_t)) override
    {
    }

    virtual void invoke_change_handlers(const par_change_flags_t change_flags) override
    {
    }

    virtual void from_byte_array(const void* array, const size_t array_size) override
    {
    }

    virtual size_t to_byte_array(void* array, const size_t array_size) const override
    {
        return size_t();
    }

    virtual size_t to_init_array(void* array, const size_t array_size) const override
    {
        return size_t();
    }

    virtual bool set_value_from_text_request(const char* text_request) override
    {
        return false;
    }

    virtual void add_to_log_pars(const char* system_name, const char* par_name) override
    {
    }

    virtual void remove_from_log_pars() override
    {
    }

    virtual unsigned int get_index() const override
    {
        return 0;
    }

    virtual unsigned int get_checksum() const override
    {
        return 0;
    }

    /*!
    * �������� �������� �� ������� ��������� ���� �� ����
    * @param par ��������-�������� ��������
    * @note ��������� ������ ����� ���� ��� (��������� ��������� - ���������� ������������ ������ ������)
    */
    virtual void set_value_from(const par_t* par) override
    {
        if (typeid(*par).name() == typeid(*this).name()) {
            const realise_par_title* a = dynamic_cast<const  realise_par_title*>(par);
            *this = *a;
        }
    }

    virtual void save() override
    {

    }

    virtual void load() override
    {

    }

    virtual void link_with(par_t* par) override
    {
    }

    virtual void unlink_from(par_t* par) override
    {
    }

};

par_title_t* create_par_title(const unsigned char list_id, const char* name) {
    return new realise_par_title(list_id, name);
}

void __stdcall destroy_par_title(par_title_t* par) {
    delete(par);
}
