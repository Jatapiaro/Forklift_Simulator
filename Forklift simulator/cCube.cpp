#include "cCube.h"

Cube::Cube( float side, bool use_mipmaps){
    this->side = side;
    hside = side / 2.0f;
    int id = 0;
    
    for( int t = 0; t < 6; t++ )
    {
        glGenTextures	(	1,
                         &targas[t].texID			);
        
        glBindTexture	(	GL_TEXTURE_2D,
                         targas[t].texID				);
        glTexEnvi		(	GL_TEXTURE_ENV,
                         GL_TEXTURE_ENV_MODE,
                         GL_REPLACE					);	// default: GL_MODULATE
        if( use_mipmaps )
        {
            glTexParameteri	(	GL_TEXTURE_2D,
                             GL_TEXTURE_MIN_FILTER,
                             GL_LINEAR_MIPMAP_NEAREST	);
        }
        else
        {
            glTexParameteri	(	GL_TEXTURE_2D,
                             GL_TEXTURE_MIN_FILTER,
                             GL_LINEAR					);
        }
        glTexParameteri	(	GL_TEXTURE_2D,
                         GL_TEXTURE_MAG_FILTER,
                         GL_LINEAR					);
        glTexParameteri	(	GL_TEXTURE_2D,
                         GL_TEXTURE_WRAP_S,
                         GL_CLAMP					);
        glTexParameteri	(	GL_TEXTURE_2D,
                         GL_TEXTURE_WRAP_T,
                         GL_REPEAT					);
        
        if( t == 0 && id==0)
        {
            LoadTGA( &targas[t],   "/Users/jacobotapia/Desktop/Forklift_Simulator/cuboMario.tga"	);
        }
        else if( t == 1 && id==0 )
        {
            LoadTGA( &targas[t],   "/Users/jacobotapia/Desktop/Forklift_Simulator/cuboMario.tga"	);
        }
        else if( t == 2 && id==0)
        {
            LoadTGA( &targas[t],   "/Users/jacobotapia/Desktop/Forklift_Simulator/cuboMario.tga"	);
        }
        else if( t == 3 && id==0)
        {
            LoadTGA( &targas[t],   "/Users/jacobotapia/Desktop/Forklift_Simulator/cuboMario.tga"	);
        }
        else if( t == 4 && id==0)
        {//top
            LoadTGA( &targas[t],   "/Users/jacobotapia/Desktop/Forklift_Simulator/cuboMario.tga"	);
        }
        else if( t == 5 && id==0)
        {//bottom
            LoadTGA( &targas[t],   "/Users/jacobotapia/Desktop/Forklift_Simulator/cuboMario.tga"	);
        }
        
        if( use_mipmaps )
        {
            gluBuild2DMipmaps(	GL_TEXTURE_2D,
                              3,
                              targas[t].width,
                              targas[t].height,
                              GL_RGB,
                              GL_UNSIGNED_BYTE,
                              targas[t].imageData			);
        }
        else
        {
            glTexImage2D	(	GL_TEXTURE_2D,
                             0,
                             GL_RGB,
                             targas[t].width,
                             targas[t].height,
                             0,
                             GL_RGB,
                             GL_UNSIGNED_BYTE,
                             targas[t].imageData			);
        }
        
        glBindTexture	(	GL_TEXTURE_2D,
                         0							);
    }
}

Cube::~Cube( void )
{
    glDeleteTextures( 1, &targas[0].texID );
    glDeleteTextures( 1, &targas[1].texID );
    glDeleteTextures( 1, &targas[2].texID );
    glDeleteTextures( 1, &targas[3].texID );
    glDeleteTextures( 1, &targas[4].texID );
    glDeleteTextures( 1, &targas[5].texID );
}

void Cube::draw( void )
{
    glBindTexture( GL_TEXTURE_2D, targas[3].texID );
    
    glBegin( GL_QUADS ); // FRONT
    glNormal3f	(  0.0f,   0.0f,  1.0f   );
    glTexCoord2f(  0.0f,   0.0f			 );
    glVertex3f	( -hside, -hside, hside  );
    
    glNormal3f	(  0.0f,   0.0f,  1.0f   );
    glTexCoord2f(  1.0f,   0.0f			 );
    glVertex3f	(  hside, -hside, hside  );
    
    glNormal3f	(  0.0f,   0.0f,  1.0f   );
    glTexCoord2f(  1.0f,   1.0f			 );
    glVertex3f	(  hside,  hside, hside  );
    
    glNormal3f	(  0.0f,   0.0f,  1.0f   );
    glTexCoord2f(  0.0f,   1.0f			 );
    glVertex3f	( -hside,  hside, hside  );
    glEnd();
    
    glBindTexture( GL_TEXTURE_2D, targas[1].texID );
    glBegin( GL_QUADS ); // RIGHT
    glNormal3f	(  1.0f,   0.0f,   0.0f  );
    glTexCoord2f(  0.0f,   0.0f			 );
    glVertex3f	(  hside, -hside,  hside );
    
    glNormal3f	(  1.0f,   0.0f,   0.0f  );
    glTexCoord2f(  1.0f,   0.0f			 );
    glVertex3f	(  hside, -hside, -hside );
    
    glNormal3f	(  1.0f,   0.0f,   0.0f  );
    glTexCoord2f(  1.0f,   1.0f			 );
    glVertex3f	(  hside,  hside, -hside );
    
    glNormal3f	(  1.0f,   0.0f,   0.0f  );
    glTexCoord2f(  0.0f,   1.0f			 );
    glVertex3f	(  hside,  hside,  hside );
    glEnd();
    
    glBindTexture( GL_TEXTURE_2D, targas[2].texID );
    glBegin( GL_QUADS ); // BACK
    glNormal3f	(  0.0f,   0.0f,  -1.0f  );
    glTexCoord2f(  0.0f,   0.0f			 );
    glVertex3f	(  hside, -hside, -hside );
    
    glNormal3f	(  0.0f,   0.0f,  -1.0f  );
    glTexCoord2f(  1.0f,   0.0f			 );
    glVertex3f	( -hside, -hside, -hside );
    
    glNormal3f	(  0.0f,   0.0f,  -1.0f  );
    glTexCoord2f(  1.0f,   1.0f			 );
    glVertex3f	( -hside,  hside, -hside );
    
    glNormal3f	(  0.0f,   0.0f,  -1.0f  );
    glTexCoord2f(  0.0f,   1.0f			 );
    glVertex3f	(  hside,  hside, -hside );
    glEnd();
    
    glBindTexture( GL_TEXTURE_2D, targas[3].texID );
    glBegin( GL_QUADS ); // LEFT
    glNormal3f	( -1.0f,   0.0f,   0.0f  );
    glTexCoord2f(  0.0f,   0.0f			 );
    glVertex3f	( -hside, -hside, -hside );
    
    glNormal3f	( -1.0f,   0.0f,   0.0f  );
    glTexCoord2f(  1.0f,   0.0f			 );
    glVertex3f	( -hside, -hside,  hside );
    
    glNormal3f	( -1.0f,   0.0f,   0.0f  );
    glTexCoord2f(  1.0f,   1.0f			 );
    glVertex3f	( -hside,  hside,  hside );
    
    glNormal3f	( -1.0f,   0.0f,   0.0f  );
    glTexCoord2f(  0.0f,   1.0f			 );
    glVertex3f	( -hside,  hside, -hside );
    glEnd();
    
    glBindTexture( GL_TEXTURE_2D, targas[4].texID );
    glBegin( GL_QUADS ); // TOP
    glNormal3f	(  0.0f,   1.0f,   0.0f  );
    glTexCoord2f(  0.0f,   0.0f			 );
    glVertex3f	( -hside,  hside,  hside );
    
    glNormal3f	(  0.0f,   1.0f,   0.0f  );
    glTexCoord2f(  1.0f,   0.0f			 );
    glVertex3f	(  hside,  hside,  hside );
    
    glNormal3f	(  0.0f,   1.0f,   0.0f  );
    glTexCoord2f(  1.0f,   1.0f			 );
    glVertex3f	(  hside,  hside, -hside );
    
    glNormal3f	(  0.0f,   1.0f,   0.0f  );
    glTexCoord2f(  0.0f,   1.0f			 );
    glVertex3f	( -hside,  hside, -hside );
    glEnd();
    
    glBindTexture( GL_TEXTURE_2D, targas[5].texID );
    glBegin( GL_QUADS ); // BOTTOM
    glNormal3f	(  0.0f,  -1.0f,   0.0f  );
    glTexCoord2f(  0.0f,   0.0f			 );
    glVertex3f	( -hside, -hside,  hside );
    
    glNormal3f	(  0.0f,  -1.0f,   0.0f  );
    glTexCoord2f(  1.0f,   0.0f			 );
    glVertex3f	(  hside, -hside,  hside );
    
    glNormal3f	(  0.0f,  -1.0f,   0.0f  );
    glTexCoord2f(  1.0f,   1.0f			 );
    glVertex3f	(  hside, -hside, -hside );
    
    glNormal3f	(  0.0f,  -1.0f,   0.0f  );
    glTexCoord2f(  0.0f,   1.0f			 );
    glVertex3f	( -hside, -hside, -hside );
    glEnd();
    glBindTexture( GL_TEXTURE_2D, 0 );
}
