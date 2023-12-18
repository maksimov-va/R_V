#include"pch.h"
#include"par_bool_t.h"
class realise_par_bool_t :public par_bool_t {
public:
	unsigned char list_id;//������������� ������ ���������� (0 - �������� �� ����������� ������)
	const char* text_id;//��������� ������������� ���������
	const char* name;//��������
	bool default_value;// �������� �� ���������
	unsigned int invalid_available; //����������� ��������� "�� �����������
	unsigned int button_type;//�������� ������


	realise_par_bool_t(const unsigned char list_id, const char* text_id, const char* name, const unsigned int button_type = PAR_BOOL_BUTTON_LARGE, const bool default_value = false, const unsigned int invalid_available = PAR_ALWAYS_VALID) {
		this->list_id = list_id;
		this->text_id = text_id;
		this->name = name;
		this->button_type = button_type;
		this->default_value = default_value;
		this->invalid_available = invalid_available;
		this->debug_value=new bool(true);
		this->debug_valid=new bool(true);
		this->debug_status=new par_status_t(PAR_STATUS_AUTO);
	}
	
	/*!
	 * ���������� ������������� ������ ����������
	 * @return ������������� ������ ����������
	 */
	virtual unsigned char get_list_id() const override
	{
		return list_id;
	}
	/*!
	 * ���������� ��������� ������������� ���������
	 * @return ��������� ������������� ���������
	 */
	virtual const char* get_text_id() const override
	{
		return text_id;
	}
	/*!
	* ���������� ��������
	* @return ��������
	*/
	virtual const char* get_name() const override
	{
		return name;
	}
	/*!
	* ���������� ������� ������������� �������� ���������
	* @return ������� ������������� �������� ���������
	* @note ���� �������� � ��������� PAR_STATUS_TEST ��� ���� �������� ������ �����������, �� ������������ true
	*/
	virtual bool get_valid() const override
	{
		return *debug_valid;
	}
	/*!
	 * ������������� ������� ������������� �������� ���������
	 * @param valid ������� ������������� �������� ���������
	 */
	virtual void set_valid(const bool valid) override
	{
		*debug_valid = valid;
	}
	/*!
	 * ���������� ���������
	 * @return ���������
	 */
	virtual par_status_t get_status() const override
	{
		return *debug_status;
	}
	/*!
	 * ������������� c��������
	 * @param status ���������
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
	* ������������� ��������� �� ���������
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
	* �������� �������� �� ������� ��������� ���� �� ����
	* @param par ��������-�������� ��������
	* @note ��������� ������ ����� ���� ��� (��������� ��������� - ���������� ������������ ������ ������)
	*/
	virtual void set_value_from(const par_t* par) override
	{
		if (typeid(*par).name() == typeid(*this).name()) {
			const realise_par_bool_t* a = dynamic_cast<const realise_par_bool_t*>(par);
			*this = *a;
		}
	}
	/*!
	 * ��������� ������� �������� � ������������� ��������� (��� ����������� ������������ ������������ ��� ������� ������ load)
	 */
	virtual void save() override
	{
		std::ofstream out("..//objekt_class.dat", std::ios::binary | std::ios::out | std::ios::_Nocreate);
		if (!out) {
			out.open("..//objekt_class.dat", std::ios::binary);
		}
		out.seekp(71);												//��� 12 ����     ������ 70 ���� �������� �������� ������� par_list_t, par_enum_t,  par_enum_read_only_t, par_double_t, par_double_read_only_t
		out.write((char*)debug_valid, sizeof(bool));
		out.write((char*)debug_value, sizeof(bool));
		out.close();
	}
	/*!
	 * ���������� ���������� �������� � ������������� ���������
	 */
	virtual void load() override
	{
		std::ifstream out("..//objekt_class.dat", std::ios::binary | std::ios::in | std::ios::_Nocreate);
		if (out) {
			out.seekg(71);											//��� 12 ����     ������ 70 ���� �������� �������� ������� par_list_t, par_enum_t,  par_enum_read_only_t, par_double_t, par_double_read_only_t
			out.read((char*)debug_valid, sizeof(bool));
			out.read((char*)debug_value, sizeof(bool));
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
   * ���������� �������� ���������
   * @return �������� ���������
   */
	virtual bool get_value() const override
	{
		return *debug_value;
	}
	/*!
   *������������� �������� ���������
   * @return �������� ���������
   */
	virtual void set_value(const bool value) override
	{
		*debug_value = value;
	}
	/*!
   *��������� �������� �� ���������
   * @return �������� �� ���������
   */
	virtual bool get_default_value() const override
	{
		return default_value;
	}
	/*!
   *��������� �������� ������
   * @return �������� ������
   */
	virtual par_bool_button_type_t get_button_type() const override
	{
		return par_bool_button_type_t(button_type);
	}
};

par_bool_t* __stdcall create_par_bool(const unsigned char list_id, const char* text_id, const char* name, const unsigned int button_type, const bool default_value, const unsigned int invalid_available) {
	return new realise_par_bool_t(list_id, text_id, name, button_type, default_value, invalid_available);
}
void __stdcall destroy_par_bool(par_bool_t* par) {
	delete par;
}