/*!
 * @file par_enum_read_only.h
 * @brief ��������-������������ ��������� (������ ��� ������)
 * @author ���� �������
 * @copyright �� ��� "�����������������", ���-1
 * @details
 * #### ����� ����
 *    ���
 * #### �����������
 *    ���
 */
#pragma once
#ifdef __cplusplus
#include "par_t.h"
#define DEBUG

 //! ��������-������������ ��������� (������ ��� ������)
class par_enum_read_only_t : public par_t {
public:
    /*!
     * ��������-������������ ��������� (������ ��� ������, ����������)
     */
    virtual ~par_enum_read_only_t() = default;

    /*!
     * ���������� ��������
     * @return ��������
     */
    virtual unsigned int get_value() const = 0;

    /*!
     * ������������� ��������
     * @param value ��������
     */
    virtual void set_value(const unsigned int value) = 0;

    /*!
     * ���������� �������� �� ���������
     * @return �������� �� ���������
     */
    virtual unsigned int get_default_value() const = 0;

    /*!
     * ���������� ����������� ��������
     * @return ����������� ��������
     */
    virtual unsigned int get_min_value() const = 0;

    /*!
     * ���������� ������������ ��������
     * @return ������������ ��������
     */
    virtual unsigned int get_max_value() const = 0;

#ifdef DEBUG
protected:
    unsigned int* debug_value;  //!< �������� (��� �������)
    bool* debug_valid;          //!< ������������� (��� �������)
    par_status_t* debug_status; //!< ��������� (��� �������)
#endif
};

/*!
 * ������� ��������-������������ ��������� (������ ��� ������)
 * @param list_id ������������� ������ ���������� (0 - �������� �� ����������� ������)
 * @param text_id ��������� ������������� ���������
 * @param name ��������
 * @param default_value �������� �� ���������
 * @param available_values ������ ���������� �������� � �� ��������, ������: "0 A;1 B;3 C"
 */
extern "C" LIBIMIT_API par_enum_read_only_t * __stdcall create_par_enum_read_only(const unsigned char list_id, const char* text_id, const char* name, const unsigned int default_value, const char* available_values);

/*!
 * ���������� ��������-������������ ��������� (������ ��� ������)
 * @par par ������������ ��������
 */
extern "C" LIBIMIT_API void __stdcall destroy_par_enum_read_only(par_enum_read_only_t * par);

#endif
