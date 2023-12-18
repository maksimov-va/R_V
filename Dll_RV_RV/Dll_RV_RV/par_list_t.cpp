#include "pch.h"
#include "par_list_t.h"
#define  DEBUG
class realise_list_t :public par_list_t {
public:
    unsigned char list_id;//идентификатор листа параметров
    const char* name;//название

    realise_list_t(const unsigned char list_id, const char* name) {
        this->list_id = list_id;
        this->name = name;
        this->debug_status = new par_status_t(PAR_STATUS_AUTO);
        this->debug_list_status =new par_list_status_t(PAR_LIST_STATUS_VALID);
        this->debug_valid = new bool(true);
    }

    /*!
       * Возвращает идентификатор списка параметров
       * @return Идентификатор списка параметров
       */
    virtual unsigned char get_list_id() const override
    {
        return list_id;
    }
    /*!
     * Возвращает текстовый идентификатор параметра
     * @return Текстовый идентификатор параметра
     */
    virtual const char* get_text_id() const override
    {
        return nullptr;
    }

    /*!
    * Возвращает название
    * @return Название
    */
    virtual const char* get_name() const override
    {
        return name;
    }
    /*!
    * Возвращает признак достоверности значения параметра
    * @return Признак достоверности значения параметра
    * @note Если параметр в состоянии PAR_STATUS_TEST или если параметр всегда достоверный, то возвращается true
    */
    virtual bool get_valid() const override
    {
        return *debug_valid;
    }
    /*!
     * Устанавливает признак достоверности значения параметра
     * @param valid Признак достоверности значения параметра
     */
    virtual void set_valid(const bool valid) override
    {
        *debug_valid = valid;
    }
    /*!
     * Возвращает состояние
     * @return Состояние
     */
    virtual par_status_t get_status() const override
    {
        return *debug_status;
    }
    /*!
     * Устанавливает cостояние
     * @param status Состояние
     */
    virtual void set_status(const par_status_t status) override
    {
        *debug_status = status;
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
    /*!
   * Устанавливает состояние по умолчанию
   */
    virtual void reset_status() override
    {
        *debug_status = PAR_STATUS_AUTO;
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
    * Копирует значение из другого параметра того же типа
    * @param par Параметр-источник значения
    * @note Параметры должны иметь один тип (текстовые параметры - одинаковый максимальный размер строки)
    */
    virtual void set_value_from(const par_t* par) override
    {
        if (typeid(*par).name() == typeid(*this).name()) {
            const realise_list_t* a = dynamic_cast<const realise_list_t*>(par);
            *this = *a;
        }
    }
    /*!
     * Сохраняет текущее значение и достоверность параметра (для возможности впоследствии восстановить его вызовом метода load)
     */
    virtual void save() override
    {
        std::ofstream out("..//objekt_class.dat", std::ios::binary | std::ios::out| std::ios::_Nocreate);
        if (!out) {
            out.open("..//objekt_class.dat", std::ios::binary);
        }
        out.seekp(std::ios::beg);
        out.write((char*)debug_valid, sizeof(bool));
        out.close();
    }
    /*!
     * Возвращает предыдущее значение и достоверность параметра
     */
    virtual void load() override
    {

        std::ifstream out("..//objekt_class.dat", std::ios::binary | std::ios::in | std::ios::_Nocreate);
        if (out) {
            out.seekg(std::ios::beg);
            out.read((char*)debug_valid, sizeof(bool));
            out.close();
        }
    }

    virtual void link_with(par_t* par) override
    {
    }

    virtual void unlink_from(par_t* par) override
    {
    }
    /*!
     * Устанавливает состояние
     * @param status Состояние
    */
    virtual void set_list_status(const par_list_status_t status) override
    {
       *debug_list_status = status;
    }
    /*!
     * Возвращает состояние
     * @return Состояние
    */
    virtual par_list_status_t get_list_status() const override
    {
        return  *debug_list_status;
    }
};

par_list_t* __stdcall create_par_list(const unsigned char list_id, const char* name) {
    return new realise_list_t(list_id, name);
}

void __stdcall destroy_par_list(par_list_t* par) {
    delete(par);
}