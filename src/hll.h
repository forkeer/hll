#ifndef AVZ_HLL_H
#define	AVZ_HLL_H

#include <sys/types.h>
#include <stdint.h>

struct HLL {
	unsigned char bits;

	size_t size;
	uint8_t *registers;
};

int hll_init(struct HLL *hll, uint8_t bits);
void hll_destroy(struct HLL *hll);

void hll_add(struct HLL *hll, const void *buf, size_t len);
void hll_add_hash(struct HLL *hll, uint32_t hash);

double hll_count(const struct HLL *hll);

#endif	/* AVZ_HLL_H */