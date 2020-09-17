CREATE DATABASE minineptun
GO
USE minineptun
GO
CREATE TABLE [hallgatok](
	[neptun] [nchar](6) NOT NULL,
	[nev] [nvarchar](30) NOT NULL,
	[telepules] [nvarchar](25) NOT NULL,
	[utca] [nvarchar](35) NOT NULL,
	[irsz] [nchar](4) NULL,
	[tel] [nvarchar](15) NULL,
	[szdat] [date] NOT NULL,
	[fiu] [bit] NULL,
	[kforma] [nchar](1) NULL,
	[tszam] [tinyint] NULL,
	[kdij] [money] NULL,
	[egyeb] [nvarchar](max) NULL,
 CONSTRAINT [PK_hallgatok] PRIMARY KEY CLUSTERED 
(
	[neptun] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [jegyek](
	[neptun] [nchar](6) NOT NULL,
	[tkod] [nvarchar](13) NOT NULL,
	[jegy] [tinyint] NOT NULL,
	[vdatum] [date] NOT NULL,
	[uv] [tinyint] NULL
) ON [PRIMARY]
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [tantargyak](
	[tkod] [nvarchar](13) NOT NULL,
	[tnev] [nvarchar](40) NOT NULL,
	[kredit] [tinyint] NOT NULL,
	[tkov] [nchar](1) NOT NULL,
 CONSTRAINT [PK_tantargyak] PRIMARY KEY CLUSTERED 
(
	[tkod] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
ALTER TABLE [hallgatok] ADD  CONSTRAINT [DF_hallgatok_telepules]  DEFAULT (N'Győr') FOR [telepules]
GO
ALTER TABLE [hallgatok] ADD  CONSTRAINT [DF_hallgatok_fiu]  DEFAULT ((1)) FOR [fiu]
GO
ALTER TABLE [jegyek] ADD  CONSTRAINT [DF_jegyek_jegy]  DEFAULT ((1)) FOR [jegy]
GO
ALTER TABLE [jegyek] ADD  CONSTRAINT [DF_jegyek_vdatum]  DEFAULT (getdate()) FOR [vdatum]
GO
ALTER TABLE [jegyek]  WITH CHECK ADD  CONSTRAINT [FK_jegyek_neptun] FOREIGN KEY([neptun])
REFERENCES [hallgatok] ([neptun])
ON UPDATE CASCADE
GO
ALTER TABLE [jegyek] CHECK CONSTRAINT [FK_jegyek_neptun]
GO
ALTER TABLE [jegyek]  WITH CHECK ADD  CONSTRAINT [FK_jegyek_tkod] FOREIGN KEY([tkod])
REFERENCES [tantargyak] ([tkod])
ON UPDATE CASCADE
GO
ALTER TABLE [jegyek] CHECK CONSTRAINT [FK_jegyek_tkod]
GO
ALTER TABLE [hallgatok]  WITH CHECK ADD  CONSTRAINT [CK_hallgatok_irsz] CHECK  (([irsz] like '[1-9][0-9][0-9][0-9]' AND CONVERT([smallint],[irsz])>=(1011) AND CONVERT([smallint],[irsz])<=(9083)))
GO
ALTER TABLE [hallgatok] CHECK CONSTRAINT [CK_hallgatok_irsz]
GO
ALTER TABLE [hallgatok]  WITH CHECK ADD  CONSTRAINT [CK_hallgatok_neptun] CHECK  (([neptun] like '[A-Z0-9][A-Z0-9][A-Z0-9][A-Z0-9][A-Z0-9][A-Z0-9]'))
GO
ALTER TABLE [hallgatok] CHECK CONSTRAINT [CK_hallgatok_neptun]
GO
ALTER TABLE [hallgatok]  WITH CHECK ADD  CONSTRAINT [CK_hallgatok_szdat] CHECK  ((dateadd(year,(18),[szdat])<=getdate()))
GO
ALTER TABLE [hallgatok] CHECK CONSTRAINT [CK_hallgatok_szdat]
GO
ALTER TABLE [hallgatok]  WITH CHECK ADD  CONSTRAINT [CK_hallgatok_tszam] CHECK  (([tszam]<=(10)))
GO
ALTER TABLE [hallgatok] CHECK CONSTRAINT [CK_hallgatok_tszam]
GO
ALTER TABLE [jegyek]  WITH CHECK ADD  CONSTRAINT [CK_jegyek_jegy] CHECK  (([jegy]>=(1) AND [jegy]<=(5)))
GO
ALTER TABLE [jegyek] CHECK CONSTRAINT [CK_jegyek_jegy]
GO
ALTER TABLE [tantargyak]  WITH CHECK ADD  CONSTRAINT [CK_tantargyak_kredit] CHECK  (([kredit]>=(0) AND [kredit]<=(30)))
GO
ALTER TABLE [tantargyak] CHECK CONSTRAINT [CK_tantargyak_kredit]
GO
ALTER TABLE [tantargyak]  WITH CHECK ADD  CONSTRAINT [CK_tantargyak_tkov] CHECK  (([tkov] like '[svf]'))
GO
ALTER TABLE [tantargyak] CHECK CONSTRAINT [CK_tantargyak_tkov]

