/* Copyright (c) 2019 Huawei Technologies Co., Ltd Limited. */

/**
 **************************************************************
 * @file acc_api.h
 *
 *
 *
 *
 * @brief This is the top level API definition for
 *        Huawei Accelerator Technology.
 *        It contains structures, data types and
 *        definitions that are common across the interface.
 *
 * @details
 *
 */

#ifndef __ACC_API_H__
#define __ACC_API_H__

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SGL_ENTRY_NUM 32
#define SGE_8K 8192
#define LEN_PAD0 2
#define LEN_PAD1 8
#define LEN_RESERVED 24

/** @addtogroup BASE_DATA_TYPES
 *  @brief is exported to users.
 *  @{
 */

/**
 * @brief compress crypto hash raid ec algorithm enumeration.
 */
typedef enum {
    ACC_ALG_LZ4 = 0, /*!< invalid */
    ACC_ALG_DEFLATE = 1, /*!< invalid */
    ACC_ALG_ZLIB     = 2, /*!< valid */
    ACC_ALG_GZIP     = 3,  /*!< valid */
    ACC_ALG_LZS      = 4, /*!< invalid */
    ACC_ALG_AES128 = 5, /*!< valid */
    ACC_ALG_AES192 = 6, /*!< valid */
    ACC_ALG_AES256 = 7, /*!< valid */
    ACC_ALG_SM4128 = 8, /*!< valid */
    ACC_ALG_DES    = 9,
    ACC_ALG_3DES   = 10,
    ACC_ALG_SHA1             = 0x20,
    ACC_ALG_SHA_256          = 0x21,
    ACC_ALG_MD5              = 0x22,
    ACC_ALG_SHA_224          = 0x23,
    ACC_ALG_SHA_384          = 0x24,
    ACC_ALG_SHA_512          = 0x25,
    ACC_ALG_SHA_512_224      = 0x26,
    ACC_ALG_SHA_512_256      = 0x27,
    ACC_ALG_HMAC_SHA1        = 0x30,
    ACC_ALG_HMAC_SHA_256     = 0x31,
    ACC_ALG_HMAC_MD5         = 0x32,
    ACC_ALG_HMAC_SHA_224     = 0x33,
    ACC_ALG_HMAC_SHA_384     = 0x34,
    ACC_ALG_HMAC_SHA_512     = 0x35,
    ACC_ALG_HMAC_SHA_512_224 = 0x36,
    ACC_ALG_HMAC_SHA_512_256 = 0x37,
    ACC_ALG_AES_XCBC         = 0x40,
    ACC_ALG_AES_CMAC         = 0x41,
    ACC_ALG_AES_GMAC         = 0x42,
    ACC_ALG_SM3              = 0x45,
    ACC_ALG_HMAC_SM3         = 0x46,
    ACC_ALG_FLEXEC	     = 0x60,
    ACC_ALG_MPCC	     = 0x61,
    ACC_ALG_BUTT,
} ACC_ALG_E;

/**
 * @brief compress operation enumeration.
 */
typedef enum {
    ACC_OPT_COMP = 0,
    ACC_OPT_DECOMP = 1,
    ACC_OPT_COMP_BUTT
} ACC_OPT_COMP_E;

/**
 * @brief ACC device idle status enumeration.
 */
typedef enum {
    ACC_BUSY = 0,
    ACC_IDLE = 1,
    ACC_IDLE_STATUS_BUTT
} ACC_IDLE_STATUS_E;

/**
 * @brief crypto operation enumeration.
 */
typedef enum {
    ACC_OPT_CRYPT_NULL          = 0x0,  /*!> 0x0:No crypto */
    ACC_OPT_ENCRYPTION_ECB = 0x1,
    ACC_OPT_ENCRYPTION_CBC = 0x2,
    ACC_OPT_ENCRYPTION_CTR = 0x3,
    ACC_OPT_ENCRYPTION_XTS = 0x4,
    ACC_OPT_ENCRYPTION_OFB = 0x5,
    ACC_OPT_DECRYPTION_ECB = 0x6,
    ACC_OPT_DECRYPTION_CBC = 0x7,
    ACC_OPT_DECRYPTION_CTR = 0x8,
    ACC_OPT_DECRYPTION_XTS = 0x9,
    ACC_OPT_DECRYPTION_OFB = 0xA,
    ACC_OPT_CRYPT_COPY     = 0xB,  /*!< Message hardware copy */
    ACC_OPT_CRYPT_BUTT
} ACC_OPT_CRYPT_E;

/**
 * @brief raid operation enumeration.
 */
typedef enum {
    ACC_OPT_GEN = 0x0, /*generate*/
    ACC_OPT_VLD = 0x1, /*validate*/
    ACC_OPT_UPD = 0x2, /*update*/
    ACC_OPT_RCT = 0x3, /*reconstruct*/
    ACC_OPT_RAID_BUTT
} ACC_OPT_RAID_E;

enum DIF_PAGE_LAYOUT_PAD_TYPE_E {
    DIF_PAGE_LAYOUT_PAD_NONE = 0x0,	/*!< 512, 520, 512+8, 4096, 4096+8, 4160 */
    DIF_PAGE_LAYOUT_PAD_AHEAD_DIF = 0x1,	/*!< 4096+56+8 */
    DIF_PAGE_LAYOUT_PAD_BEHIND_DIF = 0x2,	/*!< 4096+8+56 */
    DIF_PAGE_LAYOUT_PAD_BUTT
};

enum DIF_PAGE_LAYOUT_PAD_GEN_CTRL_E {
    DIF_PAGE_LAYOUT_PAD_GEN_NONE = 0x0,	/*!< No 56 byte completion field */
    DIF_PAGE_LAYOUT_PAD_GEN_FROM_ZERO = 0x3,	/*!< 56 byte completion field set to 0 */
    DIF_PAGE_LAYOUT_PAD_GEN_FROM_SOURCE_DATA = 0x4,	/*!< 56-byte completion field inherits from source data */
    DIF_PAGE_LAYOUT_PAD_GEN_FROM_RAID_OR_EC = 0x5,	/*!< 56 byte completion field generated by RAID/EC algorithm */
    DIF_PAGE_LAYOUT_PAD_GEN_BUTT
};

enum DIF_GRD_GEN_CTRL_E {
    DIF_GRD_GEN_NONE = 0x0,	/*!< NO GRD field */
    DIF_GRD_GEN_FROM_T10CRC = 0x1,	/*!< The GRD field is generated by the T10CRC algorithm. */
    DIF_GRD_GEN_FROM_RAID_OR_EC = 0x5,	/*!< GRD field generated by RAID/EC algorithm */
    DIF_GRD_GEN_BUTT
};

enum DIF_VER_GEN_CTRL_E {
    DIF_VER_GEN_NONE = 0x0,	/*!< NO VER field */
    DIF_VER_GEN_FROM_INPUT = 0x1,	/*!< VER field is generated by input parameters. */
    DIF_VER_GEN_FROM_ZERO = 0x3,	/*!< VER field set to 0 */
    DIF_VER_GEN_FROM_SOURCE_DATA = 0x4,	/*!< VER filed inherits from source data */
    DIF_VER_GEN_BUTT
};

enum DIF_APP_GEN_CTRL_E {
    DIF_APP_GEN_NONE = 0x0,	/*!< NO APP field */
    DIF_APP_GEN_FROM_INPUT = 0x1,	/*!< APP field is generated by input parameters */
    DIF_APP_GEN_FROM_ZERO = 0x3,	/*!< APP filed set to 0 */
    DIF_APP_GEN_FROM_SOURCE_DATA = 0x4,	/*!< APP field inherits from source data */
    DIF_APP_GEN_FROM_RAID_OR_EC = 0x5,	/*!< APP field generated by RAID/EC algorithm */
    DIF_APP_GEN_BUTT
};

enum DIF_REF_GEN_CTRL_E {
    DIF_REF_GEN_NONE = 0x0,	/*!< NO REF field */
    DIF_REF_GEN_FROM_INPUT_LBA = 0x1,	/*!< REF field generated by inputting the lower four bytes of the LBA */
    DIF_REF_GEN_FROM_PRIVATE_INFO = 0x2,	/*!< REF field generated by the lower four bytes of the private information. */
    DIF_REF_GEN_FROM_ZERO = 0x3,	/*!< REF field set to 0 */
    DIF_REF_GEN_FROM_SOURCE_DATA = 0x4,	/*!< REF field inherits from source data */
    DIF_REF_GEN_FROM_RAID_OR_EC = 0x5,	/*!< REF field generated by RAID/EC algorithm */
    DIF_REF_GEN_BUTT
};

enum DIF_VERIFY_CTRL_E {
    DIF_VERIFY_NONE = 0x0,	/*!< NO DIF field, No verified */
    DIF_VERIFY_DO_NOT_VERIFY = 0x1,	/*!< Do not perform DIF check */
    DIF_VERIFY_ALL_BLOCK = 0x2,		/*!< Verify all sectors */
    DIF_VERIFY_BY_PRIVATE_INFO = 0x3,	/*!< Only for the REF field, using the Private Info field for verification */
    DIF_VERIFY_BUTT
};

enum COMP_DATA_ALIGN_TYPE_E {
	COMP_DATA_NONE_ALIGN = 0,	/*!< Non-storage service */
	COMP_DATA_ALIGN_512B  = 512,	/*!< This configuration is supported when Block_size is 512 */
	COMP_DATA_ALIGN_1024B = 1024,	/*!< This configuration is supported when Block_size is 512 */
	COMP_DATA_ALIGN_2048B = 2048,	/*!< This configuration is supported when Block_size is 512 */
	COMP_DATA_ALIGN_4096B = 4096,	/*!< This configuration is supported when Block_size is 512 or 4096 */
	COMP_DATA_ALIGN_520B = 520,	/*!< This configuration is supported when Block_size is 520 */
	COMP_DATA_ALIGN_1040B = 1040,	/*!< This configuration is supported when Block_size is 520 */
	COMP_DATA_ALIGN_2080B = 2080,	/*!< This configuration is supported when Block_size is 520 */
	COMP_DATA_ALIGN_4160B = 4160,	/*!< This configuration is supported when Block_size is 520 or 4160 */
	COMP_DATA_ALIGN_4104B = 4104,	/*!< This configuration is supported when Block_size is 4104 */
	COMP_DATA_ALIGN_BUTT
};

enum ACC_BUF_TYPE_E {
	ACC_BUF_TYPE_PBUFFER = 0x0,
	ACC_BUF_TYPE_SGL = 0x1,
	ACC_BUF_TYPE_PRP = 0x2,
	ACC_BUF_TYPE_BUTT
} ;

/**
 * @brief WRR sched, weights is 1:2:3:4:5:6:7:8:9:10:11:12:13:14:15:16.
 */
typedef enum {
	ACC_PRT_WEIGHTS_1 = 0x0,
	ACC_PRT_WEIGHTS_2,
	ACC_PRT_WEIGHTS_3,
	ACC_PRT_WEIGHTS_4,
	ACC_PRT_WEIGHTS_5,
	ACC_PRT_WEIGHTS_6,
	ACC_PRT_WEIGHTS_7,
	ACC_PRT_WEIGHTS_8,
	ACC_PRT_WEIGHTS_9,
	ACC_PRT_WEIGHTS_10,
	ACC_PRT_WEIGHTS_11,
	ACC_PRT_WEIGHTS_12,
	ACC_PRT_WEIGHTS_13,
	ACC_PRT_WEIGHTS_14,
	ACC_PRT_WEIGHTS_15,
	ACC_PRT_WEIGHTS_16,
	ACC_PRT_BUTT,
} ACC_PRT_E;

enum PRP_TYPE_E {
    PRP_TYPE_LISTS = 0,
    PRP_TYPE_PAGES = 1,
    PRP_TYPE_BUTT
};

typedef enum {
    ACC_ATTR_ISOLATION_STRATEGY = 0,
    ACC_ATTR_BUTT,
} ACC_ATTR_CONFIG_E;

struct sgl_entry_hw {
    char *buf;		/* Start address of page data, 64bit */
    void *page_ctrl;	/* Page control header address, 64bit */
    uint32_t len;	/* Valid data length in Byte，32bit, >0 */
    uint32_t pad;	/* 32bit */
    uint32_t pad0;	/* 32bit */
    uint32_t pad1;	/* 32bit */
};

struct sgl_hw {
    struct sgl_hw *next;	/* next sgl pointer, used to form a sgl chain, 64bit */
    uint16_t entry_sum_in_chain;	/* The total number of sgl_entry in the sgl chain,
                                     * this field is valid in the first sgl of the sgl chain */
    uint16_t entry_sum_in_sgl;		/* Valid sgl entry in this sgl, >0 */
    uint16_t entry_num_in_sgl;		/* The number of sgl_entry entrys in this sgl */
    uint8_t pad0[LEN_PAD0];
    uint64_t serial_num;	/* sgl serial number*/
    uint32_t flag;		/* Data tag, used to identify whether the sgl contains zero pages, bst pages, etc. */
    uint32_t cpu_id;		/* Save the cpu when applying for the structure */
    uint8_t pad1[LEN_PAD1];
    uint8_t reserved[LEN_RESERVED];
    struct sgl_entry_hw entrys[0]; /* Sgl_entry array, the actual number is determined by entryNumInSgl */
};

struct acc_sgl {
    uint32_t src_offset; /* In the source number sgl_entry array, the actual number is determined by entryNumInSgl,
                          * and the data length is required to be offset (this calculation is not processed).
                          * Unit: Byte. */
    uint32_t dst_offset; /* The length of the offset is required in the target data, and the generated data is stored
                          * from the length after the offset. */
    struct sgl_hw *ctrl;
};

/**
 * @brief rde_ec sgl structure.
 */
struct rde_sgl {
	struct sgl_hw *ctrl;	/* source and destination data block SGL address */
	uint32_t buf_offset;	/* offset of per data disk in the SGL chain */
	uint8_t parity;		/* update mode should specify data or parity disk, data is 0, parity is 1 */
	uint8_t reserve;
	uint16_t column;	/*the index corresponding to the column of source and destination disk*/
};

struct dif_data {
    uint16_t grd;  /*16bit gurad tag, t10 crc */
    uint8_t ver;   /* dif version */
    uint8_t app;   /* An application information field reserved for the service module to store
                    * some attribute information. */
    uint32_t ref;  /* 32bit reference, lab low 32bit generally */
};

struct dif_gen {
    uint32_t page_layout_gen_type:4;	/* DIF_PAGE_LAYOUT_PAD_GEN_CTRL_E */
    uint32_t grd_gen_type:4;		/* DIF_GRD_GEN_CTRL_E */
    uint32_t ver_gen_type:4;		/* DIF_VER_GEN_CTRL_E */
    uint32_t app_gen_type:4;		/* DIF_APP_GEN_CTRL_E */
    uint32_t ref_gen_type:4;		/* DIF_REF_GEN_CTRL_E */
    uint32_t page_layout_pad_type:2;	/* DIF_PAGE_LAYOUT_PAD_TYPE_E */
    uint32_t reserved:10;
};

struct dif_verify {
    uint16_t page_layout_pad_type:2;	/* DIF_PAGE_LAYOUT_PAD_TYPE_E */
    uint16_t grd_verify_type:4;		/* DIF_VERIFY_CTRL_E */
    uint16_t ref_verify_type:4;		/* DIF_VERIFY_CTRL_E */
    uint16_t reserved:6;
};

struct dif_ctrl {
    struct dif_gen gen;
    struct dif_verify verify;
};
struct acc_dif {
    uint64_t lba;	/* Request start lba for generation or verification of dif ref field */
    uint32_t priv;	/* Private information, used to generate or verify the dif ref field */
    uint8_t ver;	/* Dif version information (storage custom), used when dif is generated */
    uint8_t app;	/* Custom fields in dif, used when dif is generated */
    struct dif_ctrl ctrl;	/* Dif generation and validation policy control field */
};

struct comp_and_xts_encrypt_alg {
    uint8_t comp_alg_type:3;	/* Chip compression algorithm not enabled when DDP_COMP_ALG_E==0 */
    uint8_t self_defined_comp_head:1;   /* 1---Store custom compression headers;
                                         * 0---No storage custom compression headers */
    uint8_t xts_encrypt_alg_type:3;	/* XTS_ENCRYPT_ALG_E */
    uint8_t reserved:1;
};

struct cipher_priv_ctrl {
    uint32_t src_offset; 	/*!< The length of the offset for the source data */
    uint32_t dst_offset; 	/*!< The length of the offset for the target data */
    struct acc_dif dif;
    uint16_t block_size;
    uint16_t gran_num;
    uint16_t key_len;
    uint8_t *key;
};

struct digest_priv_ctrl {
    uint32_t src_offset; 	/*!< The length of the offset for the source data */
    uint32_t dst_offset; 	/*!< No use for digest */
    struct acc_dif dif;
    uint16_t block_size;
    uint16_t gran_num;
};

struct exp_ctrl {
    struct acc_sgl sgl;
    struct acc_dif dif;
    void *comp_head;	/* The chip is responsible for copying the compression header to the destination area,
                         * or stripping it. */
    uint8_t buf_type;
    uint16_t block_size;
    uint16_t align_type;
    struct comp_and_xts_encrypt_alg alg;
};

struct zip_ctrl {
    struct acc_sgl sgl;
    struct acc_dif dif;
    void *comp_head;	/* The chip is responsible for copying the compression header to the destination area,
                         * or stripping it. */
    uint8_t buf_type;
    uint16_t block_size;
    uint16_t align_type;
    struct comp_and_xts_encrypt_alg alg;
    void *priv;
};

struct _cipher_ctrl {
    uint8_t *key;
    uint32_t key_len;
    uint8_t *iv;
    uint32_t iv_len;
};
struct _auth_ctrl {
    uint8_t *key;
    uint32_t key_len;
    uint8_t *iv;
    uint32_t iv_len;
};

enum SEC_FLAGS_TYPE_E {
    SEC_OPERATION_SYNC = 0x1,
    SEC_OPERATION_ASYN = 0x2,
};

/**
 * @brief sec control structure.
 */
struct sec_ctrl {
    uint8_t buf_type; /*!< @ref ACC_BUF_TYPE_E */
    uint8_t *src; /*!< source address*/
    uint8_t *dst; /*!< destination address*/
    uint32_t src_len; /*!< source data total length*/
    uint32_t dst_len; /*!< destination total length*/
    struct _cipher_ctrl cipher_ctrl; /*!< @ref _cipher_ctrl*/
    struct _auth_ctrl auth_ctrl;     /*!< @ref _auth_ctrl  */
};

/**
 * @brief ctrl information for per request,
 * user should alloc and init this structure.
 * @note
 * only mpcc support mem_saving mode, no mem_saving is 0x0, mem_saving is 0x1
 */
struct raid_ec_ctrl {
    void *src_data;	/*src data address, reference rde data structure*/
    void *dst_data;	/*dst data address, reference rde data structure*/
    uint32_t src_num; /*number of source disks*/
    uint32_t dst_num; /*number of dst disks*/
    uint32_t block_size; /*size of per block, support 512,520,4096,4104,4160*/
    uint32_t input_block; /*number of sector*/
    uint32_t data_len; /*data len of per disk, block_size (with dif)* input_block*/
    uint32_t buf_type; /*ACC_BUF_TYPE_E*/
    struct acc_dif src_dif; /*dif information of source disks*/
    struct acc_dif dst_dif; /*dif information of dest disks*/
    uint8_t cm_load; /*coe_matrix reload control, 0: do not load, 1: load*/
    uint8_t cm_len; /*length of loaded coe_matrix, equal to src_num*/
    uint8_t alg_blk_size; /*algorithm granularity, 0: 512 gran, 1: 4096 gran*/
    uint8_t mem_saving; /*mem saving or not, default 0*/
    void *coe_matrix; /*coe matrix address, should be 64byte aligned*/
    void *priv; /*design for user*/
};

typedef void (*acc_callback)(void *ctx, void *tag, int status, size_t len);
typedef void (*acc_log)(char* fmt, ...);

struct acc_ctx {
    int alg_type; /*!< @ref ACC_ALG_COMP_E, @ref ACC_ALG_CRYPT_E */
    int op_type; /*!< @ref ACC_OPT_COMP_E, @ref ACC_OPT_CRYPT_E */
    uint32_t priority; /*!< @ref ACC_PRT_E */
    uint32_t reserved;
    void *user; /*!< reserved for user */
    void *inner; /*!< reserved for SDK */
    acc_callback cb; /*!< callback function for pool and asynchronously api  */
};

/** @addtogroup ACC_DATA_TYPES
 *  @brief ACC commmon defination.
 *  @{
 */

/**
 * @brief return value.
 */
typedef enum {
    ACC_SUCCESS = 0,
    ACC_RETRY = (-101), /*!< Asynchronous callback interface status returns to retry when the engine fails */
    ACC_TMOUT = (-102), /*!< Task timeout, only involves synchronous interface */
    ACC_INVALID_PARAM = (-103), /*!< parameter error */
    ACC_UNSUPPORTED = (-104),   /*!< Debugfs access exception */
    ACC_BUSY_INSTANCE = (-105), /*!< Instance is busy*/
    ACC_FATAL_INSTANCE = (-106), /*!< Instance error */
    ACC_FATAL_ENGINE = (-107),  /*!< Hardware engine failure */
    ACC_FATAL_BUS = (-108), /*!< Bus error, not support now.*/
    ACC_ZIP_SRC_DIF_ERR = (-109),   /*!< Input data dif check error */
    ACC_ZIP_DST_DIF_ERR = (-110),   /*!< DIF check failed after decompression */
    ACC_ZIP_NEGTIVE_COMP_ERR = (-111), /*!< Negative compression */
    ACC_NO_ENGINE_AVAILABLE = (-112), /*!< Not find available engine */
    ACC_RDE_DIF_ERR = (-113), /*!< Input or Output dif check error */
    ACC_RDE_DISK_VERIFY_ERR = (-114) /*!< Output data verify error */
} ACC_STATUS_E;


/**
 *
 * @brief set T10 CRC seed.
 *
 * @param [in] seed T10 CRC seed.
 * @retval 0 is success, else is a negative number that is error code.
 *
 * @note
 * Not supported yet
 *
 */
extern int acc_set_pi_crc_seed(uint16_t seed);

/**
 *
 * @brief set the PRP page size.
 *
 * @param [in] page_size typical values: 4096 bytes, 8192 bytes.
 * @retval 0 is success, else is a negative number that is error code.
 *
 * @note
 * Not supported yet
 *
 */
extern int acc_set_prp_mem_page_size(uint32_t page_size_byte);

/**
 *
 * @brief set the offset of SGE related to SGL.
 *
 * @param [in] offset typical values: 32 bytes, 64 bytes.
 * @retval 0 is success, else is a negative number that is error code.
 *
 * @note
 * Not supported yet
 *
 */
extern int acc_set_sge_offset_from_sgl(uint32_t offset_byte);

/**
 *
 * @brief set compression Head Size.
 *
 * @param [in]
 * @param [in] size typical values: 64 bytes, 128 bytes.
 * @retval 0 is success, else is a negative number that is error code.
 *
 * @note
 * Not supported yet
 *
 */
extern int acc_set_comp_head_size(uint32_t size_byte);

/**
 *
 * @brief initialization before you call the other api.
 *
 * @param [in] ctx is the context which manage the instance.
 * @retval 0 is success, else is a negative number that is error code.
 *
 * @note
 * Be sure you will call this function first.
 *
 */
extern int acc_init(struct acc_ctx *ctx);

/**
 *
 * @brief set up the logging interface
 *
 * @param [in] log_func is the logging interface will be used.
 * @retval 0 is success, else is a negative number that is error code.
 *
 * @note
 *
 */
extern int acc_setup_log(acc_log log_func);

/**
 *
 * @brief send and receive tasks synchronously.
 *
 * @param [in] ctx is the context which manage the instance.
 * @param [in] dst is the destination address.
 * @param [in] dst_len is the destination total length.
 * @param [in] src is the source address.
 * @param [in] src_len is the source total length.
 * @retval 0 is success, else is a negative number that is error code.
 *
 * @note
 *
 */
extern int acc_update(struct acc_ctx *ctx,
        void *dst, size_t dst_len, const void *src, size_t src_len);

/**
 *
 * @brief receive the specified number of completed tasks
 *
 * @param [in] ctx is the context which manage the instance.
 * @param [in] num is the number of tasks to be charged.
 * @retval 0 is success, else is a negative number that is error code.
 *
 * @note
 *
 */
extern int acc_poll(struct acc_ctx *ctx, int num);

/**
 *
 * @brief receive the specified number of completed tasks and return the number of remaining tasks.
 *
 * @param [in] ctx is the context which manage the instance.
 * @param [in] num is the number of tasks to be charged.
 * @param [in] remainder is the number of remaining tasks.
 * @retval 0 is success, else is a negative number that is error code.
 *
 * @note
 *
 */
extern int acc_poll_v2(struct acc_ctx *ctx, int num, int *remainder);

/**
 *
 * @brief release resource that alloced by acc_init().
 *
 * @param [in] ctx is the context which manage the instance.
 * @retval 0 is success, else is a negative number that is error code.
 *
 * @note
 *
 */
extern int acc_clear(struct acc_ctx *ctx);

/**
 *
 * @brief functon level reset for acc device.
 *
 * @param [in] ctx is the context which manage the instance.
 * @retval 0 is success, else is a negative number that is error code.
 *
 * @note
 *
 */
extern int acc_dev_flr_reset(struct acc_ctx *ctx);

/**
 *
 * @brief compress data synchronously.
 *
 * @param [in] ctx is the context which manage the instance.
 * @param [in] ctrl is the parameter data of current io, use struct zip_ctrl.
 * @param [in] dst is the destination address.
 * @param [in] dst_len is the destination total length.
 * @param [in] src is the source address.
 * @param [in] src_len is the source total length.
 * @retval 0 is success, else is a negative number that is error code.
 *
 * @note
 * Multiple concurrent processing is not supported for the same instance.
 */
extern int acc_compress(struct acc_ctx *ctx, void *ctrl, void *dst, size_t *dst_len,
    void *src, size_t src_len);

/**
 *
 * @brief decompress data synchronously.
 *
 * @param [in] ctx is the context which manage the instance.
 * @param [in] ctrl is the parameter data of current io, use struct zip_ctrl.
 * @param [in] dst is the destination address.
 * @param [in] dst_len is the destination total length.
 * @param [in] src is the source address.
 * @param [in] src_len is the source total length.
 * @retval 0 is success, else is a negative number that is error code.
 *
 * @note
 * Multiple concurrent processing is not supported for the same instance.
 */
extern int acc_decompress(struct acc_ctx *ctx, void *ctrl, void *dst, size_t *dst_len,
    void *src, size_t src_len);

/**
 *
 * @brief compress data asynchronously.
 *
 * @param [in] ctx is the context which manage the instance.
 * @param [in] ctrl is the parameter data of current io, use struct zip_ctrl.
 * @param [in] dst is the destination address.
 * @param [in] dst_len is the destination total length.
 * @param [in] src is the source address.
 * @param [in] src_len is the source total length.
 * @retval 0 is success, else is a negative number that is error code.
 *
 * @note
 * Need to cooperate with the acc_poll interface to callback.
 *
 */
extern int acc_compress_asyn(struct acc_ctx *ctx, void *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);

/**
 *
 * @brief compress data asynchronously.
 *
 * @param [in] ctx is the context which manage the instance.
 * @param [in] ctrl is the parameter data of current io, use struct zip_ctrl.
 * @param [in] dst is the destination address.
 * @param [in] dst_len is the destination total length.
 * @param [in] src is the source address.
 * @param [in] src_len is the source total length.
 * @retval 0 is success, else is a negative number that is error code.
 *
 * @note
 * Need to cooperate with the acc_poll interface to callback.
 *
 */
extern int acc_decompress_asyn(struct acc_ctx *ctx, void *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_compress_encrypt(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_decrypt_decompress(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_compress_encrypt_asyn(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_decrypt_decompress_asyn(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
/**
 *
 * @brief encrypt/decrypt implementation for DES ECB mode.
 *
 * @param [in] ctx is the context which manage the instance.
 * @param [in] ctrl is the parameter data of current io, ref struct sec_ctrl.
 * @param [in] enc is flag for encrypt or decrypt, 1 for encrypt, 0 for decrypt.
 * @param [in] operation flag, ref enum SEC_FLAGS_TYPE_E.
 * @retval 0 is success, else is a negative number that is error code.
 *
 * @note
 * Multiple concurrent processing is not supported for the same instance.
 * Need to cooperate with the acc_poll interface to callback for asynchronously mode.
 *
 */
extern int acc_des_ecb64(struct acc_ctx *ctx, struct sec_ctrl *ctrl, int enc, int flag);

/**
 *
 * @brief encrypt/decrypt implementation for DES CBC mode.
 *
 * @param [in] ctx is the context which manage the instance.
 * @param [in] ctrl is the parameter data of current io, ref struct sec_ctrl.
 * @param [in] enc is flag for encrypt or decrypt, 1 for encrypt, 0 for decrypt.
 * @param [in] operation flag, ref enum SEC_FLAGS_TYPE_E.
 * @retval 0 is success, else is a negative number that is error code.
 *
 * @note
 * Multiple concurrent processing is not supported for the same instance.
 * Need to cooperate with the acc_poll interface to callback for asynchronously mode.
 *
 */
extern int acc_des_cbc64(struct acc_ctx *ctx, struct sec_ctrl *ctrl, int enc, int flag);

/**
 *
 * @brief message digest implementation with MD5 algorithm.
 *
 * @param [in] ctx is the context which manage the instance.
 * @param [in] ctrl is the parameter data of current io, ref struct sec_ctrl.
 * @param [in] operation flag, ref enum SEC_FLAGS_TYPE_E.
 * @retval 0 is success, else is a negative number that is error code.
 *
 * @note
 * Multiple concurrent processing is not supported for the same instance.
 * Need to cooperate with the acc_poll interface to callback for asynchronously mode.
 *
 */
extern int acc_md5(struct acc_ctx *ctx, struct sec_ctrl *ctrl, int flag);

/**
 *
 * @brief hmac implementation with MD5 algorithm.
 *
 * @param [in] ctx is the context which manage the instance.
 * @param [in] ctrl is the parameter data of current io, ref struct sec_ctrl.
 * @param [in] operation flag, ref enum SEC_FLAGS_TYPE_E.
 * @retval 0 is success, else is a negative number that is error code.
 *
 * @note
 * Multiple concurrent processing is not supported for the same instance.
 * Need to cooperate with the acc_poll interface to callback for asynchronously mode.
 *
 */
extern int acc_hmac_md5(struct acc_ctx *ctx, struct sec_ctrl *ctrl, int flag);

extern int acc_hmac_sha256(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_aes_cmac128(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_aes_gmac128(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_aes_gmac128(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_aes_ccm128(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_aes_gcm128(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_hmac_sha1_truncated96(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_hmac_sha256_truncated128(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_aes128_cts_cbc(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_aes256_cts_cbc(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_pbk_df2(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_ddp_fp_cal_by_sha(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_aes_xts256_encrypt(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_aes_xts256_decrypt(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_sm4_xts128_encrypt(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_sm4_xts128_decrypt(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_hmac_sha256_asyn(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_aes_cmac128_asyn(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_aes_gmac128_asyn(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_aes_gmac128_asyn(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_aes_ccm128_asyn(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_aes_gcm128_asyn(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_hmac_sha1_truncated96_asyn(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_hmac_sha256_truncated128_asyn(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_aes128_cts_cbc_asyn(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_aes256_cts_cbc_asyn(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_pbk_df2_asyn(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_ddp_fp_cal_by_sha_asyn(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_aes_xts256_encrypt_asyn(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_aes_xts256_decrypt_asyn(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_sm4_xts128_encrypt_asyn(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
extern int acc_sm4_xts128_decrypt_asyn(struct acc_ctx *ctx, struct exp_ctrl *ctrl,
        void *dst, size_t dst_len, const void *src, size_t src_len);
/**
 *
 * @brief flexec/raid5/raid6 operation asynchronously.
 *
 * @param [in] ctx is the context which manage the instance.
 * @param [in] ctrl is the parameter data of current io.
 * @param [in] op_type is from ACC_OPT_RAID_E
 * @retval 0 is success, else is a negative number that is error code.
 *
 * @note
 * Multiple concurrent processing is not supported for the same instance.
 */
extern int acc_do_flexec_asyn(struct acc_ctx *ctx,
        struct raid_ec_ctrl *ctrl, uint8_t op_type);

/**
 *
 * @brief mpcc operation asynchronously.
 *
 * @param [in] ctx is the context which manage the instance.
 * @param [in] ctrl is the parameter data of current io.
 * @param [in] op_type is from ACC_OPT_RAID_E
 * @retval 0 is success, else is a negative number that is error code.
 *
 * @note
 * Multiple concurrent processing is not supported for the same instance.
 */
extern int acc_do_mpcc_asyn(struct acc_ctx *ctx,
        struct raid_ec_ctrl *ctrl, uint8_t op_type);

/**
 *
 * @brief flexec/raid5/raid6 operation synchronously.
 *
 * @param [in] ctx is the context which manage the instance.
 * @param [in] ctrl is the parameter data of current io.
 * @param [in] op_type is from ACC_OPT_RAID_E
 * @retval 0 is success, else is a negative number that is error code.
 *
 * @note
 * Multiple concurrent processing is not supported for the same instance.
 */
extern int acc_do_flexec(struct acc_ctx *ctx,
        struct raid_ec_ctrl *ctrl, uint8_t op_type);

/**
 *
 * @brief mpcc operation synchronously.
 *
 * @param [in] ctx is the context which manage the instance.
 * @param [in] ctrl is the parameter data of current io.
 * @param [in] op_type is from ACC_OPT_RAID_E
 * @retval 0 is success, else is a negative number that is error code.
 *
 * @note
 * Multiple concurrent processing is not supported for the same instance.
 */
extern int acc_do_mpcc(struct acc_ctx *ctx,
        struct raid_ec_ctrl *ctrl, uint8_t op_type);

/**
 *
 * @brief get the number of available devices.
 *
 * @param [in] alg_type is the algorithm type which defined in enum ACC_ALG_E.
 * @param [in] num is the number of available devices.
 * @retval 0 is success, else is a negative number that is error code.
 *
 * @note
 *
 */
extern int acc_get_available_dev_num(int alg_type, int *num);

/**
 *
 * @brief get the idle state of specified device.
 *
 * @param [in] alg_type is the algorithm type which defined in enum ACC_ALG_E.
 * @param [in] state is the idle state of specified device.
 * @retval 0 is success, else is a negative number that is error code.
 *
 * @note
 * When there are multiple devices, as long as one device is busy, it will return busy.
 *
 */
extern int acc_get_dev_idle_state(int alg_type, int *state);

/**
 *
 * @brief get config value according to algorithm.
 *
 * @param [in] alg_type is the algorithm type.
 * ACC_ALG_ZLIB/ACC_ALG_GZIP correspond compression engine.
 * ACC_ALG_AES128 ~ ACC_ALG_HMAC_SM3 correspond cryptographic engine.
 * @param [in] config_type is the supported configuration enum.
 * @param [out] value is the configuration's content.
 * @retval 0 is success, else is a negative number that is error code.
 *
 * @note
 * This interface does not support concurrent use. Do not support VF.
 *
 */
extern int acc_get_config(int alg_type, int config_type, int *value);

/**
 *
 * @brief set config value according to algorithm.
 *
 * @param [in] alg_type is the algorithm type.
 * ACC_ALG_ZLIB/ACC_ALG_GZIP correspond compression engine.
 * ACC_ALG_AES128 ~ ACC_ALG_HMAC_SM3 correspond cryptographic engine.
 * @param [in] config_type is the supported configuration enum.
 * @param [in] value is the content that needs to be configured.
 * Range is 0 ~ 65535.
 * @retval 0 is success, else is a negative number that is error code.
 *
 * @note
 * Cannot use set configuration interface when using business, will return busy.
 * This interface does not support concurrent use. Do not support VF.
 *
 */
extern int acc_set_config(int alg_type, int config_type, int value);


#ifdef __cplusplus
}
#endif

#endif /* __ACC_API_H__ */