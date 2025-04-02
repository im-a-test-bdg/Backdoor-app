/*
 * Proprietary Software License Version 1.0
 *
 * Copyright (C) 2025 BDG
 *
 * Backdoor App Signer is proprietary software. You may not use, modify, or distribute it except as expressly permitted
 * under the terms of the Proprietary Software License.
 */

#include "base64.h"
#include <string.h>

#define B0(a) (a & 0xFF)
#define B1(a) (a >> 8 & 0xFF)
#define B2(a) (a >> 16 & 0xFF)
#define B3(a) (a >> 24 & 0xFF)

ZBase64::ZBase64(void) {}

ZBase64::~ZBase64(void) {
    if (!m_arrEnc.empty()) {
        for (size_t i = 0; i < m_arrEnc.size(); i++) {
            delete[] m_arrEnc[i];
        }
        m_arrEnc.clear();
    }

    if (!m_arrDec.empty()) {
        for (size_t i = 0; i < m_arrDec.size(); i++) {
            delete[] m_arrDec[i];
        }
        m_arrDec.clear();
    }
}

unsigned char ZBase64::s_ca_table_enc[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
