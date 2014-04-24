#ifndef PHONE_TYPE_H
#define PHONE_TYPE_H

/**
 * Enum that represents the phone number type.
 * Home, Mobile, Work, and Fax are standard labels and represented with
 * just the enum.
 * If the phone type is PT_CUSTOM, then a custom label (string) can
 * be applied to the PhoneNumber
 */
enum PhoneType {
  PT_HOME,
  PT_MOBILE,
  PT_WORK,
  PT_FAX,
  PT_CUSTOM
};

#endif