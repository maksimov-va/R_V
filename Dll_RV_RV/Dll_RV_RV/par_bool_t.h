/*!
 * @file par_bool.h
 * @brief ������� �������� ���������
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

 //! ������� �������� ���������
class par_bool_t : public par_t {
public:
    /*!
     * ������� �������� ��������� (����������)
     */
    virtual ~par_bool_t() = default;

    /*!
     * ���������� ��������
     * @return ��������
     */
    virtual bool get_value() const = 0;

    /*!
     * ������������� ��������
     * @param value ��������
     */
    virtual void set_value(const bool value) = 0;

    /*!
     * ���������� �������� �� ���������
     * @return �������� �� ���������
     */
    virtual bool get_default_value() const = 0;

    /*!
     * ���������� ��� ������
     * @return ��� ������
     */
    virtual par_bool_button_type_t get_button_type() const = 0;

#ifdef DEBUG
protected:
    bool* debug_value;          //!< �������� (��� �������)
    bool* debug_valid;          //!< ������������� (��� �������)
    par_status_t* debug_status; //!< ��������� (��� �������)
#endif
};

/*!
 * ������� ������� �������� ���������
 * @param list_id ������������� ������ ���������� (0 - �������� �� ����������� ������)
 * @param text_id ��������� ������������� ���������
 * @param name ��������
 * @param button_type ��� ������ (par_bool_button_type_t)
 * @param default_value �������� �� ���������
 * @param invalid_available ����������� ��������� "�� �����������" (par_invalid_available_t)
 */
extern "C" LIBIMIT_API par_bool_t * __stdcall create_par_bool(const unsigned char list_id, const char* text_id, const char* name, const unsigned int button_type = PAR_BOOL_BUTTON_LARGE, const bool default_value = false, const unsigned int invalid_available = PAR_ALWAYS_VALID);

/*!
 * ���������� ������� �������� ���������
 * @par par ������������ ��������
 */
extern "C" LIBIMIT_API void __stdcall destroy_par_bool(par_bool_t * par);

#endif
