import os
from mutagen.mp3 import MP3
from mutagen.id3 import ID3, APIC
from PIL import Image
from io import BytesIO
import sys

def extract_cover(file_path, image_path):
    print(f"Python file is open")
    
    try:
        if os.path.exists(image_path):
            os.remove(image_path)

        audio = MP3(file_path, ID3=ID3)
        for tag in audio.tags.values():
            if isinstance(tag, APIC):
                image_data = tag.data
                image = Image.open(BytesIO(image_data))
                image.save(image_path)
                print(f"Cover image saved to {image_path}")
                return
        print("No APIC frame found")
    except Exception as e:
        print(f"Error: {str(e)}")

if __name__ == "__main__":
    mp3_file_path = sys.argv[1]
    output_image_path = sys.argv[2]
    extract_cover(mp3_file_path, output_image_path)

