from pptx2md import convert, ConversionConfig
from pathlib import Path

# Basic usage
convert(
    ConversionConfig(
        pptx_path=Path('/home/ruizhe/Github/Code/Python/annual_report.pptx'),
        output_path=Path('annual_report.md'),
        image_dir=Path('img'),
        disable_notes=True
    )
)