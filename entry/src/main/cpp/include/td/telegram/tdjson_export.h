#pragma once

#if defined(_WIN32)
#if defined(TDJSON_EXPORTS)
#define TDJSON_EXPORT __declspec(dllexport)
#else
#define TDJSON_EXPORT __declspec(dllimport)
#endif
#else
#define TDJSON_EXPORT __attribute__((visibility("default")))
#endif
