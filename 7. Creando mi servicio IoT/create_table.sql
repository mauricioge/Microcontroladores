CREATE TABLE `iot_th` (
  `id_th` char(36) COLLATE utf8_unicode_ci NOT NULL,
  `mac` char(17) COLLATE utf8_unicode_ci NOT NULL,
  `tmp` varchar(6) COLLATE utf8_unicode_ci NOT NULL,
  `hmd` varchar(6) COLLATE utf8_unicode_ci NOT NULL,
  `ct` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id_th`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
